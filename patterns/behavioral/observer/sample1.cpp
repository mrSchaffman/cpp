/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include <iostream>
#include <vector>
#include <algorithm>


class ObserverInterface
{
public:
    virtual ~ObserverInterface() = default; 
    virtual void notify() = 0;
};

class UserInterfaceObserver : public ObserverInterface
{
public:
    void notify() override { std::cout << "UserInterfaceObserver::notify()" << std::endl; }
};

class EntityObserver : public ObserverInterface
{
public:
    void notify() override { std::cout << "EntityObserver::notify()" << std::endl; }
};

namespace service
{
    namespace publisher
    {
        class Publisher
        {
        private:
            std::vector<ObserverInterface *> m_observers;

        public:
            void addObserver(ObserverInterface *observer)
            {
                m_observers.push_back(observer);
            }
            void removeObserver(ObserverInterface *observer)
            {
                m_observers.erase(std::remove(begin(m_observers), end(m_observers), observer), end(m_observers));
            }
            void notifyAllObservers()
            {
                for (auto *observer : m_observers)
                    observer->notify();
            }
            Publisher() {}
            virtual ~Publisher()
            {
                // TODO
            }
        };

    } // namespace publisher
    
} // namespace service

namespace user_interaction
{
    class UserInterface : private service::publisher::Publisher
    {
    public:
        using Publisher::addObserver;
        using Publisher::notifyAllObservers;
        using Publisher::removeObserver;
    
    public:
        virtual ~UserInterface() = default;
        virtual void sendInput(/*some data */) = 0;
    };

    namespace gui
    {
        class Gui : public UserInterface
        {
        public:
            Gui() = default;
            virtual void sendInput(/*some data */) override
            {
                // TODO
                notifyAllObservers();
            }
            void pushOkBtn()
            {
                // TODO
                notifyAllObservers();
            }
        };

    } // namespace gui
    
} // namespace user_interaction



int main()
{
    using namespace user_interaction::gui;
    Gui dialogWindow;

    UserInterfaceObserver observer1;
    dialogWindow.addObserver(&observer1);

    dialogWindow.pushOkBtn();

    std::cout << std::endl;

    EntityObserver observer2;
    dialogWindow.addObserver(&observer2);

    dialogWindow.pushOkBtn();

    return 0;
}