/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/
#include <memory>

class BankAccount
{
private:
    double m_soldo{};

public:
    BankAccount(/* args */) {}
    ~BankAccount() {}
    void deposit(int amout);
};

int main()
{

    BankAccount *ba = new BankAccount;
    ba->deposit(123); // same API

    // using make_shared is the illustration of a proxy
    auto ba2 = std::make_shared<BankAccount>();
    ba2->deposit(123); // same API

    return 0;
}