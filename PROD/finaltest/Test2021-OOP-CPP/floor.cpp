#include "floor.h"
#include <ctime>
using namespace std;

Floor::Floor()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            bool random=rand() %2;
            if(random==true){
                floor[i][j] = new GreenTile();
            }else{
                floor[i][j] = new BlueTile();
            }
        }
    }
}

Floor::~Floor()
{
    for (int i = 0; i < 3; i++) {
            delete[] floor[i];
    }
    delete[] floor;
}

void Floor::print(){
    cout << " ____________\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << "| ";
            floor[i][j]->display();
        }
        cout << "|\n|___|___|___|\n";
    }
}

void Floor::mark(int x, int y){
    floor[x][y]->mark();
    cout << "Tile at " << x << " " << y << "was marked\n";
}

void Floor::replace(int x, int y){
    if(floor[x][y]->getColor() == 'G'){
        floor[x][y] = new BlueTile();
    }
    if(floor[x][y]->getColor() == 'B' && floor[x][y]->isMarked()){
        floor[x][y] = new RedTile();
    }
}

bool Floor::isRed(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(floor[i][j]->getColor()!='R'){
                return false;
            }
        }
    }
    return true;
}
