/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include<vector>
namespace entity
{
    class Point
    {
    private:
        double m_x{};
        double m_y{};
    public:
        Point(double x,double y):m_x(x),m_y(y) {}
        ~Point() {}
        double getX()const{return m_x;}
        double getY()const{return m_y;}
    };

    class Line
    {
    private:
        Point m_start;
        Point m_end;
    public:
        Line(Point pt1, Point pt2):m_start{pt1},m_end{pt2} {}
        ~Line() {}
        Point getStart()const{return m_start;}
        Point getEnd()const{return m_end;}
    };

    using Lines = std::vector<Line>;
    using LinesIterator = Lines::iterator;

    class LineCollectionInterface
    {
    public:
        virtual LinesIterator begin()=0;
        virtual LinesIterator end()=0;
    public:
        virtual ~LineCollectionInterface() {}
    };

    class Rectangle : private LineCollectionInterface
    {
    private:
        Lines m_lines;
    public:
        LinesIterator begin()override{return m_lines.begin();};
        LinesIterator end()override{return m_lines.end();};
        Rectangle(Point pt1, Point pt2) {
            // TODO: construct the rectangle here...
        }
        ~Rectangle() {}
    };

} // namespace entity

namespace externalAPI
{
    // API working only with Points...

    using PointsIterator = std::vector<Point>::iterator;
    struct TargetDC
    {
        setPixelAt(entity::Point p){
            // implementation....
        }
    };

    class PointsDrawer
    {
    public:
        void draw(TargetDC & dc, PointsIterator start, PointsIterator end){
            for (auto iter= start; iter !=end; ++iter)
               dc.setPixelAt(*iter);
               
        }
    };
    
} // namespace externalAPI

// my Adaptor for the API

namespace adaptor
{
    using Points=std::vector<Point>;
    using PointsIterator=std::vector<Point>::iterator;
    
    class LineToPointAdaptor
    {
    private:
        Points m_points;

    public:
        LineToPointAdaptor(entity::Line & line) {
            // discretisation of the Line here
            // m_point.emplace_back(something)
        }
        ~LineToPointAdaptor() {}
        PointsIterator begin(){return m_points.begin();};
        PointsIterator end(){return m_points.end();};

    };
} // namespace adaptor


int main(){


    // use the adapter
    std::vector<entity::Line> lines{/*...*/};
    for (auto & p: lines)
    {
        adaptor::LineToPointAdaptor lineAdaptor{p};

        // use the external API
        externalAPI::PointsDrawer drw;
        externalAPI::TargetDC dc;
        drw.draw(dc,lineAdaptor.begin(), lineAdaptor.end());
        
    }
    
}