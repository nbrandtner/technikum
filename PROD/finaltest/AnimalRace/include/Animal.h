#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;


class Animal
{
    public:
        Animal(std::string animalName, int distance);
        virtual ~Animal();

        virtual void run() = 0;

        bool atGoal();

        void trick(Animal* animalToBeTricked);

        string getName();
        int getDistanceToGoal();

    protected:

        string name;
        int distanceToGoal;
        bool confused;

    private:
};

#endif // ANIMAL_H
