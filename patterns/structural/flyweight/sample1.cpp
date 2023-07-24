/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * 
*/

// in the Forest, there is many Trees

#include<string>
#include<map>
namespace entity
{
    class TreeBase
    {
    private:
        std::string m_name,m_color,texture{};       // would whole objects...
    public:
        TreeBase(const std::string& name,std::string&color,std::string&texture):m_name{name},m_color{color},m_texture{texture} {}
        virtual~Tree() {}
    };

    class TreeFactory
    {
    private:
        std::map<std::string,TreeBase> m_trees;
    public:
        TreeFactory() {

        }
        ~TreeFactory() {}
    };

    class Tree
    {
    private:
        double m_x{},m_y{};
        TreeBase & m_heavyTree;
    public:
        Tree(double x,double y):m_x{x},m_y{y} {}
        ~Tree() {}
    };


} // namespace entity
