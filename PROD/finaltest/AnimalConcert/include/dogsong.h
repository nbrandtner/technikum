#ifndef DOGSONG_H
#define DOGSONG_H
#include <vector>

#include <ianimalsong.h>


class DogSong : public IAnimalSong
{
    public:
        DogSong();
        virtual ~DogSong();
        char getTypeChar();
        int play(std::vector<IAnimalSong*>& songs,int index);

    protected:

    private:
};

#endif // DOGSONG_H
