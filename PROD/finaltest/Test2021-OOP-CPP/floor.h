#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <cstdlib>
#include "Tile.h"
#include "redtile.h"
#include "bluetile.h"
#include "greentile.h"

class Floor
{
    public:
        Floor();
        virtual ~Floor();
        void print();
        void mark(int x, int y);
        void replace(int x, int y);
        bool isRed();


    protected:
        Tile* floor[3][3];
    private:

};

#endif // FLOOR_H
