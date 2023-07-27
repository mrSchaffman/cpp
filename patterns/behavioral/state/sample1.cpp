/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
 */
#include <iostream>
#include <string>
/*
     Light
     has only two states:
     - on
     - off
 */

namespace entity
{

    class Light; // Forward Declaration

    struct State
    {
        virtual void setOn(Light *ls)
        {
            std::cout << "Light is already on\n";
        }
        virtual void setOff(Light *ls)
        {
            std::cout << "Light is already off\n";
        }
    };

    struct OnState : State
    {
        OnState() { action(); }
        void setOff(Light *ls) override
        {
            std::cout << "Light turned off\n";
            ls->setState(new OnState());

            delete this;
        }

        void action()
        {
            std::cout << "Light turned on\n";
        }
    };
    struct OffState : State
    {
        OffState() { action(); }
        void setOn(Light *ls) override
        {
            std::cout << "Switching Light on\n";
            ls->setState(new OffState());

            delete this;
        }
        void action()
        {
            std::cout << "Light turned off\n";
        }
    };

    class Light
    {
    public:
        Light()
        {
            state = new OffState();
        }
        void setState(State *state)
        {
            this->state = state;
        }

        void on() { state->setOn(this); }
        void off() { state->setOff(this); }

        ~Light()
        {
            delete state;
        }

    private:
        State *state{nullptr};
    };

} // namespace entity
int main()
{
    using namespace entity;
    Light ls;
    ls.on();  // Switching light on...
              // Light turned on
    ls.off(); // Switching light off...
              // Light turned off
    ls.off(); // Light is already off

    return 0;
}
