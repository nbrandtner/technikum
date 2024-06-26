#include "Rabbit.h"

using namespace std;

Rabbit::Rabbit(string animalName, int distance): Animal(animalName, distance)
{
    //ctor
}

Rabbit::~Rabbit()
{
    //dtor
}

void Rabbit::run()
{
    if(asleep == false && confused == false){
        distanceToGoal -= 3;

        if(distanceToGoal != 0){
            if(rand()%3 == 1){
                asleep = true;
                cout << "The Rabbit fell asleep " << distanceToGoal << " from the goal";
            }
        }


    } else if (asleep == true) {
        if(rand()%3 == 1){
            asleep = false;
        }
    } else if (confused == true){
        if(rand()%3 == 1){
            confused = false;
        }
    }

}
