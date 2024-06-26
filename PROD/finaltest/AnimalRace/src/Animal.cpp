#include "Animal.h"

using namespace std;

Animal::Animal(string animalName, int distance)
{
    //ctor
    name = animalName;
    distanceToGoal = distance;
    confused = false;
}

Animal::~Animal()
{
    //dtor
}

bool Animal::atGoal()
{
    if(distanceToGoal < 1){
        return true;
    }

    return false;
}

void Animal::trick(Animal* animalToBeTricked)
{
    if(!animalToBeTricked){
        throw invalid_argument("Opponent NULL");
    }

    if(this->distanceToGoal - animalToBeTricked->distanceToGoal > 5){
        throw logic_error("Opponent too far away");
    }

    if(rand()%6 == 1){
        animalToBeTricked->confused = true;
        cout << "The " << animalToBeTricked->name << " got distracted";
    }
}

string Animal::getName()
{
    return name;
}

int Animal::getDistanceToGoal()
{
    return distanceToGoal;
}
