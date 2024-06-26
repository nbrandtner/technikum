#include "roostersong.h"
#include <stdexcept>
#include <iostream>
using namespace std;

RoosterSong::RoosterSong()
{
    //ctor
}

RoosterSong::~RoosterSong()
{
    //dtor
}

char RoosterSong::getTypeChar(){
    return 'R';
}

int RoosterSong::play(vector<IAnimalSong*>& songs,int index){
    if(index < 0 || index >= songs.size()){
        throw invalid_argument("Out of Bounds");
    }
    int counter=0;
    for(int i = 0;i<songs.size();i++){
        if(songs[i]->getTypeChar()=='R'){
            counter++;
        }
    }
    if(counter==1){
        return 3;
    }
    return 0;
}
