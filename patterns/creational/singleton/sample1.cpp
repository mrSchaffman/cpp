/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

// Singleton as Global Data
#include<string>
namespace logic
{
    namespace manager
    {
        class EntityManager
        {
        public:
            EntityManager& getInstance(){
                static EntityManager instance;
                return instance;
            }

            // eventually add CRUD functions here...
            // ...
            void add(const std::string & entity){
                // TODO
                m_database.push(entity);
            }
        public:
            ~EntityManager()=default;

        private:
            EntityManager()=default;

        private:
            EntityManager(const EntityManager&)=delete;
            EntityManager( EntityManager&&)=delete;
            EntityManager& operator=(const EntityManager&)=delete;
            EntityManager& operator=( EntityManager&&)=delete;

        private:
            using DummyData = std::vector<std::string>;
            DummyData m_database{};
        };
        
    } // namespace manager
    
} // namespace logic

int main(){
    using namespace std;
    std::string entity1="dummy name";
    
    using namespace logic::manager;
    EntityManager::getInstance().add(entity1);

    return 0;
}