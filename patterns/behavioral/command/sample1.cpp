/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
 */
class Stack
{
public:
    Stack &Instance()
    {
        static Stack instance;
        return instance;
    }
    unsigned int size()const;
    void pop(bool);
    void push(void *);

private:
    Stack() {}
    // ...
};
class Command
{
public:
    virtual ~Command();
    void execute()
    {
        checkPreconditionsImpl(); // Coming from the use case
        executeImpl();
        checkPostconditionsImpl();

        return;
    }
    void undo();
    Command *clone() const; // which will be use in the prototyp pattern

    const char *helpMessage() const;

protected:
    Command();
    Command(const Command &);

private:
    virtual void checkPreconditionsImpl() const;
    virtual void checkPostconditionsImpl() const;

    virtual void executeImpl() noexcept = 0;
    virtual void undoImpl() noexcept = 0;
    virtual Command *cloneImpl() const = 0;
    virtual const char *helpMessageImpl() const noexcept = 0;
};

class UnaryCommand : public Command
{
public:
    virtual ~UnaryCommand();

protected:
    void checkPreconditionsImpl() const override;
    UnaryCommand() {}
    UnaryCommand(const UnaryCommand &);
    void UnaryCommand::checkPreconditionsImpl() const
    {
        if (Stack::Instance().size() < 1)
            throw Exception{"Stack must have one element"};
    }

    // The executeImpl() command is also quite straightforward :
    void UnaryCommand::executeImpl() noexcept
    {
        top_ = Stack::Instance().pop(true);
        Stack::Instance().push(unaryOperation(top_));
    }
    void UnaryCommand::undoImpl() noexcept
    {
        Stack::Instance().pop(true);
        Stack::Instance().push(top_);
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
    double unaryOperation(double t) const override { return std::sin(t); }
};
