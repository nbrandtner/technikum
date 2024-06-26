#include <iostream>
#include "concert.h"
#include "dogsong.h"
#include "catsong.h"
#include "roostersong.h"
#include <stdexcept>

using namespace std;

Concert::Concert(std::string songString)
{
    for(char s : songString)
    {
        switch(s)
        {
            case 'C': songs.push_back(new CatSong());
            break;
            case 'D': songs.push_back(new DogSong());
            break;
            case 'R': songs.push_back(new RoosterSong());
        }
    }
}

Concert::~Concert()
{
    for(auto song: songs){
        delete song;
    }
    songs.clear();
}

int Concert::play() {
    int concertSum = 0;
    for (int i = 0; i < songs.size(); ++i) {
        try {
            concertSum += songs[i]->play(songs, i);
        } catch (const invalid_argument& e) {
            std::cerr << "Invalid Argument" << std::endl;
        } catch (const exception& e) {
            std::cerr << "Error" << std::endl;
        }
    }
    return concertSum;
}
