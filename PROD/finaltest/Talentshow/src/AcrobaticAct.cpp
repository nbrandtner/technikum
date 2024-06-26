#include "AcrobaticAct.h"
#include <iostream>
#include <stdexcept>
#include <exception>

AcrobaticAct::AcrobaticAct(int intens)
{
    if(intens>0){
        intensity=intens;
    }
}

AcrobaticAct::~AcrobaticAct()
{
    //dtor
}

char AcrobaticAct::getType(){
    return 'A';
}
int AcrobaticAct::getValue(std::vector<AbstractAct*>& program, int index){
    if(index<0||index>=program.size()){
        throw std::out_of_range("Index is out of Range");
    }
    int acroCounter=0;
    for(int i=0;i<=index;i++){
        if(program[i]->getType()=='A'){
            acroCounter++;
        }
    }
    if(acroCounter>3){
        std::cout << "AcrobaticAct intensity: " << 1 << std::endl;
        return 1;
    }
    std::cout << "AcrobaticAct intensity: " << intensity+3 << std::endl;
    return intensity;
}
