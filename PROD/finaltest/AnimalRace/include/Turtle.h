#ifndef TURTLE_H
#define TURTLE_H

#include <Animal.h>
using namespace std;


class Turtle : public Animal
{
    public:
        Turtle(string animalName, int distance);
        virtual ~Turtle();

        void run();

    protected:

    private:
};

#endif // TURTLE_H
