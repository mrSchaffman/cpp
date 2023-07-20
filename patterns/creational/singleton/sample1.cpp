/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

// Singleton as Global Data
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
        public:
            ~EntityManager()=default;

        private:
            EntityManager()=default;

        private:
            EntityManager(const EntityManager&)=delete;
            EntityManager( EntityManager&&)=delete;
            EntityManager& operator=(const EntityManager&)=delete;
            EntityManager& operator=( EntityManager&&)=delete;
        };
        
    } // namespace manager
    
} // namespace logic
