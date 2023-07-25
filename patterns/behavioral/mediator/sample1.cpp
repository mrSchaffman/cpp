/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

#include<string>
#include<vector>
#include<algorithm>
namespace entity
{
    class GroupMember
    {
    private:
        std::string m_name{};
        std::vector<std::string> m_message{};
        WhatsappGroup *m_group{nullptr};

    public:
        GroupMember(const std::string & name):m_name{name} {}
        ~GroupMember() {}
        void setGroup(WhatsappGroup *grp) { m_group = grp; }
        void newMessage(const std::string &msg) { m_message.push_back(msg); }
        std::string getName() const { return m_name; }
    };

    // The Mediator
    class WhatsappGroup     
    {
    private:
        std::vector<GroupMember*> m_persons{};

    public:
        WhatsappGroup(unsigned int maxSize) {
            m_persons.reserve(maxSize);
        }
        ~WhatsappGroup() {}

        void join(GroupMember * member){
            notify(member->getName()+ " just Joined");
            m_persons.push_back(member);
            member->setGroup(this);
        }
        void notify(const std::string &message){
            std::transform(m_persons.begin(), m_persons.end(), [&](GroupMember &member){ member.newMessage(message); });
        }
    };
} // namespace entity
