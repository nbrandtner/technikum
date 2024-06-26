#include <iostream>
#include <TalentShow.h>

using namespace std;

int main()
{
    int fridayIntensities [] = {3, 5, 6, 7, 4, 3, 8, 4, 5, 6};
    int saturdayIntensities [] = {7, 6, 5, 4, 8, 5, 6, 7, 4, 2};
    int sundayIntensities [] = {3, 8, 4, 5, 6, 5, 6, 7, 4, 3};
    TalentShow friday("MASMMSASAA", fridayIntensities);
    TalentShow saturday("SSSAAAMMMS", saturdayIntensities);
    TalentShow sunday("SMASMMAASS", sundayIntensities);
    int fridayVal = friday.itsShowtime();
    int saturdayVal = saturday.itsShowtime();
    int sundayVal = sunday.itsShowtime();
    std::cout << "On Friday the excitement was " << fridayVal;
    std::cout << "\nOn Saturday the excitement was " << saturdayVal;
    std::cout << "\nOn Sunday the excitement was " << sundayVal << std::endl;
    return 0;
}
