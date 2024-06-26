#ifndef ROOSTERSONG_H
#define ROOSTERSONG_H
#include <vector>

#include <ianimalsong.h>


class RoosterSong : public IAnimalSong
{
    public:
        RoosterSong();
        virtual ~RoosterSong();
        char getTypeChar();
        int play(std::vector<IAnimalSong*>& songs,int index);

    protected:

    private:
};

#endif // ROOSTERSONG_H
