#include "SongAct.h"
#include <iostream>
#include <stdexcept>

SongAct::SongAct(int intens)
{
    if(intens>0){
        intensity=intens;
    }
}

SongAct::~SongAct()
{
    //dtor
}

char SongAct::getType(){
    return 'S';
}
int SongAct::getValue(std::vector<AbstractAct*>& program, int index){
    if(index<0||index>=program.size()){
        throw std::out_of_range("Index is out of Range");
    }
    bool acrobatic=false;
    for(int i = index;i>index-3;i--){
        if(i>=0){
            if(program[i]->getType()=='A'){
                acrobatic=true;
            }
        }
    }
    if(acrobatic){
        std::cout << "SongAct intensity: " << intensity+3 << std::endl;
        return intensity+3;
    }
    std::cout << "SongAct intensity: " << intensity << std::endl;
    return intensity;
}
