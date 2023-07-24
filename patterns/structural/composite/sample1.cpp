/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include<vector>
#include<algorithm>
namespace service
{
    class DrawableInterface
    {
    public:
        virtual~DrawableInterface() {}
        virtual void draw()=0;
    };
    class MovableInterface
    {
    public:
        virtual~MovableInterface() {}
        virtual void move(double,double)=0;
    };
} // namespace service

namespace entity
{
    class GraphicInterface : private service::DrawableInterface, private service::MovableInterface
    {  
    public:
        using service::DrawableInterface::draw;
        using service::MovableInterface::move;
    public:
        GraphicInterface() {}
        virtual~GraphicInterface() {}
    };

    class CompositeGraphic : public GraphicInterface
    {
    public:
        using Graphics = std::vector<GraphicInterface>;
    private:
        Graphics m_graphics{};
    public:
        CompositeGraphic(/* args */) {}
        ~CompositeGraphic() {}
    public:
        void add(const GraphicInterface & g){
            // TODO
            // avoiding duplicates...
            if (std::any_of(std::cbegin(m_graphics),std::cend(m_graphics),[&](const GraphicInterface & other){return g == other;}))     // should implement the == operator...
                return;
            else
                m_graphics.emplace_back(g);
        }
        void remove(const GraphicInterface & g){
            // TODO
        }

        virtual void move(double x, double y)override{
            std::transform(std::begin(m_graphics),std::end(m_graphics),[&](GraphicInterface &g){
                    g.move(x,y);
                }
            );
        }
        virtual void draw()override{
            // TODO...
        }
    };

    // the Leaf of the Composite Structure
    class Point : public GraphicInterface
    {
    protected:
        double m_x{}, m_y{};
    public:
        Point(double x, double y):m_x{x},m_y{y} {}
        virtual void move(double x, double y)override{
            std::cout << "previous Position: "<<m_x<<", "<<m_y<<"\n";
            m_x+=x;
            m_y+=y;
            std::cout << "new Position: "<<m_x<<", "<<m_y<<"\n";
        }
        virtual void draw()override{
            // TODO...
        }

        virtual~Point() {}
    };
    class Circle: public GraphicInterface // private Point
    {
    public:
	    Circle(Point center,double radius):m_center{center}, m_raduis{radius}{}
	    virtual~Circle() = default;
	    virtual void draw() override{/* To Do */ }
        virtual void move(double x, double y)override{
            m_center.move(x,y);
        }
    private:
	    double m_raduis{};
        Point m_center{};
    };
} // namespace entity

int main(){
    using namespace entity;
    Point p1(2.1,4.6);
    Point p2(6.3,46.1);
    Point p3(7.1,3.1);
    Point p4(30.0,100.5);
    Circle c1(p4,10.0);
    CompositeGraphic myComposite;
    
    myComposite.add(p1);
    myComposite.add(p2);
    myComposite.add(p3);
    myComposite.add(c1);

    p1.move(12.4,10.0);

    // select a group and move
    myComposite.move(5.0,2.0);
}

