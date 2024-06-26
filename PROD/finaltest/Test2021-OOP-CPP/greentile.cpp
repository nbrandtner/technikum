#include "greentile.h"

GreenTile::GreenTile()
{
    marked=true;
}

GreenTile::~GreenTile()
{
    //dtor
}

void GreenTile::mark(){
    marked=true;
}

char GreenTile::getColor(){
    return 'G';
}
