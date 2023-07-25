/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include<vector>
namespace entity
{
    class AccountMemento
    {
    private:
        double m_balance{};

    public:
        explicit AccountMemento(double balance) : m_balance{balance} {}
        double getBalance() const { return m_balance; }
    };
    class Account
    {
    private:
        double m_balance{};
        std::vector<AccountMemento> m_changes{};

    public:
        explicit Account(double balance = 0.0) : m_balance{balance} {}
        double getBalance() const { return m_balance; }
        void deposit(double amount){
            m_balance += amount;
            AccountMemento memento(m_balance);
            m_changes.push_back(memento);
        }
        void undo(){
            if(!m_changes.empty()){
                auto lastState = m_changes.back();
                m_balance = lastState.getBalance();
                m_changes.pop_back();
            }
        }

        std::vector<AccountMemento> getChanges() const { return m_changes; }
    };
  
    
} // namespace entity
