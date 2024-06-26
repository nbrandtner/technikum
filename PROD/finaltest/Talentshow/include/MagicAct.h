#ifndef MAGICACT_H
#define MAGICACT_H
#include <vector>

#include <AbstractAct.h>


class MagicAct : public AbstractAct
{
    public:
        MagicAct(int intens);
        virtual ~MagicAct();
        char getType();
        int getValue(std::vector<AbstractAct*>& program, int index);

    protected:

    private:
};

#endif // MAGICACT_H
