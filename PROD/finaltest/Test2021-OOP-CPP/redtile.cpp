#include "redtile.h"

RedTile::RedTile(){
    marked = false;
}

RedTile::~RedTile()
{
    //dtor
}

void RedTile::mark(){
    marked=false;
}

char RedTile::getColor(){
    return 'R';
}
