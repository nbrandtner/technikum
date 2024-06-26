#include <iostream>
#include <vector>
#include "Concert.h"

using namespace std;

int main()
{
    // Test cases with different song strings
    vector<string> testCases = {
        "DDDDCR",   // Expected score: 7
        "DDD",      // Expected score: 3
        "CCC",      // Expected score: 15
        "R",        // Expected score: 3
        "DRC",      // Expected score: 8
        "RRR",      // Expected score: 0
        "CDC"       // Expected score: 8
    };

    // Iterate through each test case
    for (const auto& songString : testCases) {
        Concert concert(songString);

        // Let the band play
        int score = concert.play();

        // Print final score
        cout << "For song string "" << songString << "", the band reached a score of " << score << endl;
    }

    return 0;
}
