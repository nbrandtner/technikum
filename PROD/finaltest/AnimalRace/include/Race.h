#ifndef RACE_H
#define RACE_H
#include <vector>
#include "Animal.h"
#include <stdexcept>


class Race
{
    public:
        Race();
        virtual ~Race();

        void competition();
        void addAnimal(Animal* animalToAdd);
        bool raceFinished();
        void printResult();
        void trickEachother();

    protected:

        vector<Animal*> animalList;

};

#endif // RACE_H
