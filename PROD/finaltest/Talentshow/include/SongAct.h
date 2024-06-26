#ifndef SONGACT_H
#define SONGACT_H
#include <vector>

#include <AbstractAct.h>


class SongAct : public AbstractAct
{
    public:
        SongAct(int intens);
        virtual ~SongAct();
        char getType();
        int getValue(std::vector<AbstractAct*>& program, int index);

    protected:

    private:
};

#endif // SONGACT_H
