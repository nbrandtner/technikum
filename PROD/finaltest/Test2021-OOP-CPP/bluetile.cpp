#include "bluetile.h"
#include <ctime>

BlueTile::BlueTile()
{
    marked = rand() %2;
}

BlueTile::~BlueTile()
{
    //dtor
}

void BlueTile::mark(){
    marked=true;
}

char BlueTile::getColor(){
    return 'B';
}
