/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/
#include<map>
#include<string>
class Facade
{
private:
    std::map<size_t,std::string> m_about{};
public:
    Facade() {
        m_about.emplace_back(1,"this system can do 1");
        m_about.emplace_back(2,"this system can do 2");
        m_about.emplace_back(3,"this system can do 3");
        m_about.emplace_back(4,"this system can do 4");
        m_about.emplace_back(5,"this system can do 5");
    }
    ~Facade() {}
    void run();
    std::string getAboutn(size_t n);
};