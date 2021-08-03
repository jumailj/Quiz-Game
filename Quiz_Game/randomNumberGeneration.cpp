#include "core.h"


int GenerateRandomNumber(int min, int max)
{


    int randomNumber = 0;
start:
    randomNumber = rand() % (max + 1);

    if (randomNumber < min) {
        goto start;
    }

    return randomNumber;

}
