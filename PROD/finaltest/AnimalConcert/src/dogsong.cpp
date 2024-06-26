#include "dogsong.h"
#include <stdexcept>
#include <iostream>
using namespace std;

DogSong::DogSong()
{
    //ctor
}

DogSong::~DogSong()
{
    //dtor
}

char DogSong::getTypeChar(){
    return 'D';
}


int DogSong::play(vector<IAnimalSong*>& songs,int index){
    int prevIndex=index-1;
    int nextIndex=index+1;

    if(index < 0 || index >= songs.size()){
        throw invalid_argument("Out of Bounds");
    }

    if (index == 0) {
        if (songs.size() > 1 && songs[nextIndex]->getTypeChar() == 'C') {
            return 0;
        } else {
            return 1;
        }
    }

    if (index == songs.size() - 1) {
        if (songs[prevIndex]->getTypeChar() == 'C') {
            return 0;
        } else {
            return 1;
        }
    }

    if(songs[prevIndex]->getTypeChar()=='C' || songs[nextIndex]->getTypeChar()=='C'){
        return 0;
    }
    return 1;
}
