/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
 */

#include <memory>
namespace entity
{
    namespace request
    {
        class RequestInterface
        {
        public:
            virtual ~RequestInterface() {}
        };

        class SoundRequest : public RequestInterface
        {
        private:
            double m_date{};

        public:
            SoundRequest(double d):m_date{d} {}
            double getState() const { return m_date; }
            ~SoundRequest() {}
        };
    } // namespace request
    namespace specification
    {
        class RequestSpecificationInterface
        {
        public:
            virtual ~RequestSpecificationInterface() {}
            virtual bool is_satisfied(const entity::request::RequestInterface &request) = 0;
        };

        class SoundSpecification : public RequestSpecificationInterface
        {            
        public:
            SoundSpecification() {}
            virtual bool is_satisfied(const entity::request::RequestInterface &request){
                // TODO : Downcast
                if( request.getState() >= 200)
                    return false;
                else
                    return true;
            };
        };
    } // namespace specification

} // namespace entity

namespace business_logic
{
    namespace handler
    {
        class HandlerInterface
        {
        public:
            virtual ~HandlerInterface() {}
            virtual void handle(const entity::request::RequestInterface &) = 0;
        };

        class Handler : public HandlerInterface
        {
        private:
            std::unique_ptr<HandlerInterface> m_next;

        public:
            Handler(std::unique_ptr<HandlerInterface> nextHanlder) : m_next{std::move(nextHanlder)} {}

            virtual void handle(const entity::request::RequestInterface &request) override
            {
                if (m_next)
                    m_next->handle(request);
            }

            virtual ~Handler() {}
        };
        class SoundHandler : public Handler
        {
        private:
            entity::specification::RequestSpecificationInterface &m_soundSpecification;

        public:
            SoundHandler(entity::specification::RequestSpecificationInterface &spec, std::unique_ptr<HandlerInterface> nextHanlder)
                : Handler(std::move(nextHanlder)), m_soundSpecification(spec) {}

            virtual void handle(const entity::request::RequestInterface &request) override
            {
                if (m_soundSpecification.is_satisfied(request))
                {
                    // handler and pas to the next hanlder
                    // ...
                    Handler::handle(request);
                }
                else
                {
                    // cannot go futher, 
                }
            }
        };

        class NotificationHandler : public Handler
        {
        public:
            NotificationHandler() : Handler (nullptr){}

            virtual void handle(const entity::request::RequestInterface &request) override
            {
                // TODO : Downcast
                auto data = request.getState();
                // do some logging or what ever with it...
            }
        };

    } // namespace handler

} // namespace business_logic


int main(){
    using namespace entity;
    request::SoundRequest sRequest(10.0);

    specification::SoundSpecification sSpec;

    using namespace business_logic::handler;
    std::unique_ptr<NotificationHandler> nHandler;
    SoundHandler sHandler(sSpec,nHandler);

    sHandler.handle(sRequest);
}