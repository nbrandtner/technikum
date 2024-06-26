#ifndef TALENTSHOW_H
#define TALENTSHOW_H
#include <string>
#include <vector>
#include "AbstractAct.h"
#include "MagicAct.h"
#include "SongAct.h"
#include "AcrobaticAct.h"


class TalentShow
{
    public:
        TalentShow(std::string program, int intensityArr []);
        virtual ~TalentShow();
        int itsShowtime();

    protected:

    private:
        std::vector<AbstractAct*> program;
};

#endif // TALENTSHOW_H
