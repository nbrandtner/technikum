#include "Turtle.h"

Turtle::Turtle(string animalName, int distance): Animal(animalName, distance)
{
    //ctor
}

Turtle::~Turtle()
{
    //dtor
}

void Turtle::run()
{
    if(confused == false){
        distanceToGoal -= 1;
    } else if (confused == true){
        int chance = rand()%3;
        if(chance == 1 || chance == 2){
            confused = false;
        }
    }
}
