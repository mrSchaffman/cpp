/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/
#include<string>

namespace entity
{
    class DataInterface
    {   
    public:
        virtual~DataInterface() {}
    };

    class StringData :public DataInterface
    {
    private:
        std::string m_data{}
    public:
        StringData(const std::string& str):m_data{str} {}
        std::string getData()const{return m_data;}
        ~StringData() {}
    };
} // namespace entity

namespace service
{
    namespace encripter
    {
        class EncripterInterface        // the Decorator
        {
        private:
            
        public:
            virtual entity::DataInterface& encript(entity::DataInterface &data)=0;
            virtual~EncripterInterface() {}
        };

        class StringWithIntEncripter:public EncripterInterface
        {
        public:
            virtual entity::DataInterface& encript(entity::DataInterface &data)override{
                // TODO: downcast
                auto result = "123"+ data.getData() + "123";    //dummy encription
                return new entity::StringData(result);      // TODO: memory management
            };
        
        };
    } // namespace encripter
    
    namespace logger
    {
        class LoggerInterface
        {
        public:
            virtual void log(entity::DataInterface & data)=0;
            virtual~LoggerInterface() {}
        };

        class FileLogger : public LoggerInterface
        {
        private:
            std::string m_filename{};
        public:
            FileLogger(const std::string & filename):m_filename{filename} {}
            ~FileLogger() {}
            virtual void log(entity::DataInterface & data)override{
                // TODO...
            }

        };

        // advanced FileLogger using a the Encripter
        class AdvancedFileLogger : public FileLogger
        {
        private:
            encripter::EncripterInterface & m_encripter;
        public:
            AdvancedFileLogger(encripter::EncripterInterface &encripter,const std::string filename):FileLogger(filename),m_encripter{encripter} {}
            ~AdvancedFileLogger() {}
            virtual void log(entity::DataInterface & data)override{
                // encript the data
                auto encriptedData = m_encripter.encript(data);
                FileLogger::log(encriptedData);
            }

        };
    } // namespace logger
    
} // namespace service

int main(){
    std::string myName{"barth.feudong"};
    entity::StringData data(myName);
    std::string filename{"text.txt"};

    // log my name
    service::encripter::StringWithIntEncripter strEncripter;
    service::logger::AdvancedFileLogger aLogger(strEncripter,filename);

    aLogger.log(data);
    return 0;
}