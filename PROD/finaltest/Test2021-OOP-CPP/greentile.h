#ifndef GREENTILE_H
#define GREENTILE_H

#include <iostream>
#include <stdlib.h>
#include "Tile.h"

class GreenTile:public Tile{
    public:
        GreenTile();
        virtual ~GreenTile();

        char getColor();
        void mark();
    protected:

    private:
};

#endif // GREENTILE_H
