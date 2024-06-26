#include "MagicAct.h"
#include <iostream>
#include <stdexcept>
using namespace std;

MagicAct::MagicAct(int intens)
{
    if(intens>0){
        intensity=intens;
    }
}

MagicAct::~MagicAct()
{
    //dtor
}

char MagicAct::getType(){
    return 'M';
}
int MagicAct::getValue(std::vector<AbstractAct*>& program, int index){
    if(index<0||index>=program.size()){
        throw std::out_of_range("Index is out of Range");
    }
    if(index>0){
        if(program[index-1]->getType()=='M'){
            std::cout << "MagicAct intensity: " << intensity/2 << endl;
            return intensity/2;
        }else{
            std::cout << "MagicAct intensity: " << intensity << endl;
            return intensity;
        }
    }
    std::cout << "MagicAct intensity: " << intensity << endl;
    return intensity;
}
