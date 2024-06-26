#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <stdlib.h>

class Tile
{
    public:
        Tile();
        virtual ~Tile();
        bool isMarked();  //Return if the tile is marked for replacement
        void display();   //Prints one character for the color
        virtual char getColor()=0;
        virtual void mark()=0;
    protected:
        bool marked;      //Defines if the tile is marked to be replaced

    private:

};

#endif // TILE_H
