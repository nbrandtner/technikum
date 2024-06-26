#ifndef ABSTRACTACT_H
#define ABSTRACTACT_H
#include <vector>


class AbstractAct
{
    public:
        AbstractAct();
        virtual ~AbstractAct();
        virtual char getType()=0;
        virtual int getValue(std::vector<AbstractAct*>& program, int index)=0;

    protected:
        int intensity;
    private:
};

#endif // ABSTRACTACT_H
