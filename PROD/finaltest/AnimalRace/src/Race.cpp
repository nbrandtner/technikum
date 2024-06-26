#include "Race.h"

using namespace std;

Race::Race()
{
    //ctor
}

Race::~Race()
{
    //dtor
    for(auto animal : animalList) {
        delete animal;
    }

    animalList.clear();
}

void Race::competition()
{
    //Racing loop
    while(!raceFinished())
    {

        for(Animal* tmpAnimal: animalList)
        {
            tmpAnimal->run();
        }

        // try catch block
        try{
            trickEachother();
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }
    }

    printResult();
}

void Race::addAnimal(Animal* animalToAdd)
{
    animalList.push_back(animalToAdd);
}

bool Race::raceFinished()
{
    for(int i = 0; i < animalList.size(); i++){
        if(animalList[i]->getDistanceToGoal() <= 0){
            return true;
        }
    }
    return false;
}

void Race::printResult()
{
    for(int i = 0; i < animalList.size(); i++){
        cout << animalList[i]->getName() << " is " << animalList[i]->getDistanceToGoal() << " away from the goal" << endl;
    }

}

void Race::trickEachother()
{
        for(int i = 0; i < animalList.size(); i++){
            animalList[i]->trick(animalList[rand()%animalList.size()]);
        }
}
