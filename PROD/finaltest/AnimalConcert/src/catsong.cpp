#include "catsong.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CatSong::CatSong()
{
    //ctor
}

CatSong::~CatSong()
{
    //dtor
}

char CatSong::getTypeChar(){
    return 'C';
}


int CatSong::play(vector<IAnimalSong*>& songs,int index){

    int counter = 0;
    if(index < 0 || index >= songs.size()){
        throw invalid_argument("Out of Bounds");
    }
    if(index > 0 && index < songs.size()){
        for(int i = 0; i < index; i++){
            if(songs[i]->getTypeChar()=='D'){
                counter++;
            }
        }
    }
    return 5-counter;

}
