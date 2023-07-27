/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
 */

#include <list>
namespace entity
{
    class Point
    {
    private:
        double m_x{}, m_y{};

    public:
        Point(double x, double y) : m_x(x), m_y(y) {}
        ~Point() {}
    };
    class Node
    {
    private:
        Node *m_left{nullptr};
        Node *m_right{nullptr};

    public:
        Node(double p1, double p2) {}
        //...
        ~Node() { delete m_left, m_right; }
    };
} // namespace entity

namespace algorithm
{
    enum class AlgoType
    {
        GoingOnRoadAlgorithm,
        UsingBicycleAlgorithm,
        UsingPublicTransportAlgorithm,
    };
    class IsAlgorithm
    {
    public:
        virtual ~IsAlgorithm() {}
    };

    class RouteAlgorithm : public IsAlgorithm
    {
    public:
        virtual ~RouteAlgorithm() {}
        virtual std::list<entity::Node *> build(entity::Node *start, entity::Node *end) = 0;
    };
    class GoingOnRoadAlgorithm : public RouteAlgorithm
    {
    public:
        virtual ~GoingOnRoadAlgorithm() {}
        virtual std::list<entity::Node *> build(entity::Node *start, entity::Node *end) override
        {
            // TODO
        }
    };
    class UsingBicycleAlgorithm : public RouteAlgorithm
    {
    public:
        virtual ~UsingBicycleAlgorithm() {}
        virtual std::list<entity::Node *> build(entity::Node *start, entity::Node *end) override
        {
            // TODO
        }
    };
    class UsingPublicTransportAlgorithm : public RouteAlgorithm
    {
    public:
        virtual ~UsingPublicTransportAlgorithm() {}
        virtual std::list<entity::Node *> build(entity::Node *start, entity::Node *end) override
        {
            // TODO
        }
    };
} // namespace algorithm

namespace planner
{
    class RoutPlanner
    {
    public:
        RoutPlanner() {}
        virtual ~RoutPlanner() {}
        virtual std::list<entity::Node *> plan(const std::vector<entity::Node *>, entity::Node *, entity::Node *, algorithm::AlgoType algo)
        {
            switch (algo)
            {
            case algorithm::AlgoType::GoingOnRoadAlgorithm:
                // TODO
                break;
            case algorithm::AlgoType::UsingBicycleAlgorithm:
                // TODO
                break;
            case algorithm::AlgoType::UsingPublicTransportAlgorithm:
                // TODO
                break;

            default:
                break;
            }
        };
    };
} // namespace planner

namespace entity
{
    class Navigator
    {
    public:
        Navigator() {}
        std::list<Node *> plan(algorithm::AlgoType strategy, Node *start, Node *destination)
        {
            return m_planner.plan(m_nodes, start, destination, algorithm::AlgoType::UsingBicycleAlgorithm);
        }

    private:
        std::vector<Node *> m_nodes{};
        planner::RoutPlanner &m_planner;
    };

} // namespace entity

int main()
{
    using namespace entity;
    auto start = new Node(0.0, 1.42);
    auto destination = new Node(40.3, 50.2);

    Navigator navi;
    navi.plan(algorithm::AlgoType::GoingOnRoadAlgorithm, start, destination);
    return 0;
}