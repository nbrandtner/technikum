#include "TalentShow.h"
#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;

TalentShow::TalentShow(std::string program, int intensityArr [])
{
    for(int i = 0; i < program.size(); i++) {
        char curr = program.at(i);
        switch(curr) {
        case 'M':
            this->program.push_back(new MagicAct(intensityArr[i]));
            break;
        case 'S':
            this->program.push_back(new SongAct(intensityArr[i]));
            break;
        case 'A':
            this->program.push_back(new AcrobaticAct(intensityArr[i]));
            break;
        }
    }
}

int TalentShow::itsShowtime() {
    int intensitySum=0;
    for(int i=0;i<program.size();i++){
        try{
            intensitySum+=program[i]->getValue(program, i);
        }catch(std::out_of_range& e){
            std::cout << "Error: Out of Range" << endl;
        }catch(std::exception& e){
            std::cout << "Other Error :(" << endl;
        }
    }
    return intensitySum;
}

TalentShow::~TalentShow()
{
}
