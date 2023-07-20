/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.Feudong
*/
#include<string>

// Email sender Service
namespace mailer
{

    namespace entity
    {
        class Email
        {
        private:
            std::string from{}, to{},,object{},subject{},body{};
        public:
            Email()=default;
            ~Email()=default;
            void to(std::string&t){to=t;};
            void from(std::string&f){from=t};
            void subject(std::string&s){subject=s};
            void object(std::string&o){object=o};
        };
        
        
    } // namespace entity

    namespace logic
    {
        class EmailBuilder
        {
        private:
            entity::Email &email;
        public:
            EmailBuilder(entity::Email &mail):email{msil}{};
            ~EmailBuilder()=default;
        public:
            EmailBuilder& from(std::string f){
                email.from(f);
                return *this;
            }
            EmailBuilder& to(std::string t){
                email.to(t);
                return *this;
            }
            EmailBuilder& subject(std::string s){
                email.subject(s);
                return *this;
            }
            EmailBuilder& object(std::string o){
                email.object(f);
                return *this;
            }
        };
        
      
    } // namespace logic
    
    // the Facade of the Mailer Service
    class Mailer
    { 
    public:
        Mailer()=default;
        ~Mailer()=default;
    public:
        void send(std::function<void(EmailBuilder&)>builder){
            entity::Email email;
            logic::EmailBuilder bder{email};

            builder(bder);
            sendImpl(email);
        }
    private:
        void sendImpl(const entity::Email&email){
            // send the email here...
            
        }
    };
} // namespace mailer

int main(){

    // without direct interaction with the Email Entity

    auto mbuilder=[&](mailer::logic::EmailBuilder & builder){
        builder.from("dummy@mail.com");
        builder.to("dummyTo@email");
        builder.subject("dummy Subject");
        builder.object("Dummy object");
    };

    mailer::Mailer _mailer;
    _mailer.send(mbuilder);

    return 0;
}