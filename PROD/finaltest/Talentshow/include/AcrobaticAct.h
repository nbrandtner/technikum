#ifndef ACROBATICACT_H
#define ACROBATICACT_H
#include <vector>

#include <AbstractAct.h>


class AcrobaticAct : public AbstractAct
{
    public:
        AcrobaticAct(int intens);
        virtual ~AcrobaticAct();
        char getType();
        int getValue(std::vector<AbstractAct*>& program, int index);

    protected:

    private:
};

#endif // ACROBATICACT_H
