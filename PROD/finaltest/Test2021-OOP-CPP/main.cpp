#include <iostream>
#include "floor.h"
#include <ctime>
using namespace std;

int main()
{
    srand(time(nullptr));
    Floor boden=Floor();
    int x,y;
    while(!boden.isRed()){
        boden.print();
        x=rand()%3;
        y=rand()%3;
        try{
            boden.mark(x,y);
            boden.replace(x,y);
        }catch(const invalid_argument& e){
            cerr << "Error: Invalid Argument :(";
        } catch (const std::exception& e) {
            cerr << "Error :(";
        }
    }
    boden.print();
}
