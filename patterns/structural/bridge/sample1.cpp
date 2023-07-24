/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include<iostream>
// we want to draw a Family of entities: Shape 
// wo is supposed to draw: the Renderer Family
// The What is: Shapes
// The Who is: Renderers
// The Where is: ???
namespace service
{
    // Who...
    class CircleRendererInterface
    {  
    public:
        virtual void render_circle(double x,double y,double radius)=0;
        virtual~CircleRendererInterface() {}
    };

    // Rendere Type 1
    class VectorRenderer: public CircleRendererInterface
    { 
    public:
        virtual void render_circle(double x,double y,double radius){
            //TODO...
            std::cout<<"How to draw a Circle with Vector"
            <<x<<"-"
            <<y<<"-"
            <<radius
            <<std::endl;
        };

    };
    class CustomRenderer: public CircleRendererInterface
    { 
    public:
        virtual void render_circle(double x,double y,double radius){
            //TODO...
            std::cout<<"How to draw a Circle with with my own implemented renderer"
            <<x<<"-"
            <<y<<"-"
            <<radius
            <<std::endl;
        };

    };

    class DrawableInterface
    { 
    public:
        virtual void draw()=0;
        virtual~DrawableInterface() {}
    };
    
    class ResizableInterface
    { 
    public:
        virtual void resize(double factor)=0;
        virtual~ResizableInterface() {}
    };

} // namespace service

namespace entity
{

    // What to draw
    class ShapeInterface : private service::DrawableInterface, private service::ResizableInterface
    {
    protected:
        service::RendererInterface &m_render;
   
    public:
        ShapeInterface(service::RendererInterface & renderer):m_render{renderer}{}
        virtual~ShapeInterface() {}
    };

    class Circle : public ShapeInterface
    {
    private:
        double m_x;
        double m_y;
        double m_radius;
    public:
        Circle(double x,double y, double radius, service::RendererInterface & renderer ):ShapeInterface(renderer)m_x(x),m_y(y),m_radius{radius} {}
        ~Circle() {}
        virtual void draw()override{
                m_render.render_circle(m_x,m_y,m_radius)
        }
        virtual void resize(double factor)override{

        }
    };

} // namespace entity


int main(){
    using namespace service;
    CustomRenderer myRenderer;
    
    using namespace entity;
    Circle myCircle(23.3,43.0,20,myRenderer);
    myCircle.draw();
    
    return 0;
}