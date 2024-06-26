#ifndef BLUETILE_H
#define BLUETILE_H

#include <iostream>
#include <stdlib.h>
#include "Tile.h"

class BlueTile:public Tile{
    public:
        BlueTile();
        virtual ~BlueTile();
        char getColor();
        void mark();

    protected:

    private:
};

#endif // BLUETILE_H
