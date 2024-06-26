#ifndef CATSONG_H
#define CATSONG_H
#include <vector>

#include <ianimalsong.h>


class CatSong : public IAnimalSong
{
    public:
        CatSong();
        virtual ~CatSong();
        char getTypeChar();
        int play(std::vector<IAnimalSong*>& songs,int index);

    protected:

    private:
};

#endif // CATSONG_H
