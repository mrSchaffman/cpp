/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
 */
#include<cmath.h>

namespace entity
{
    namespace command
    {
        class CommandInterface
        {
        public:
            virtual ~CommandInterface();
            void execute()
            {
                checkPreconditionsImpl(); // Coming from the use case
                executeImpl();
                checkPostconditionsImpl();

                return;
            }
            void undo();
            CommandInterface *clone() const; // which will be use in the prototyp pattern

            const char *helpMessage() const;

        protected:
            CommandInterface();
            CommandInterface(const CommandInterface &);

        private:
            virtual void checkPreconditionsImpl() const;
            virtual void checkPostconditionsImpl() const;

            virtual void executeImpl() noexcept = 0;
            virtual void undoImpl() noexcept = 0;
            virtual CommandInterface *cloneImpl() const = 0;
            virtual const char *helpMessageImpl() const noexcept = 0;
        };

        class UnaryCommand : public CommandInterface
        {
        public:
            virtual ~UnaryCommand();

        protected:
            void checkPreconditionsImpl() const override;
            UnaryCommand() {}
            UnaryCommand(const UnaryCommand &);
            void UnaryCommand::checkPreconditionsImpl() const
            {
               // TODO
            }

            // The executeImpl() command is also quite straightforward :
            void UnaryCommand::executeImpl() noexcept
            {
                // TODO
            }
            void UnaryCommand::undoImpl() noexcept
            {
                // TODO
            }

        private:
            void executeImpl() noexcept override;
            void undoImpl() noexcept override;
            virtual double unaryOperation(double top) const = 0;
            double top_;
        };

        class Sine : public UnaryCommand
        {
        private:
            double unaryOperation(double t) const override { 
                return std::sin(t); 
            }
        };
    } // namespace command
    
} // namespace entity

