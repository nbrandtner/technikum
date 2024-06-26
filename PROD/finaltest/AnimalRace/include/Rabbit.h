#ifndef RABBIT_H
#define RABBIT_H

#include <Animal.h>

using namespace std;


class Rabbit : public Animal
{
    public:
        Rabbit(string animalName, int distance);
        virtual ~Rabbit();

        void run();

    protected:

        bool asleep;

    private:
};

#endif // RABBIT_H
