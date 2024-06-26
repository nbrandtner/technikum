#ifndef REDTILE_H
#define REDTILE_H

#include <iostream>
#include <stdlib.h>
#include "Tile.h"

class RedTile:public Tile{
    public:
        RedTile();
        virtual ~RedTile();
        char getColor();
        void mark();

    protected:

    private:
};

#endif // REDTILE_H
