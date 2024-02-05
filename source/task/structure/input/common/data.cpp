#include "task/structure/input/common/data.h"

#include "input/boundary.h"
#include "input/advanced/randomizer.h"

Randomizer<char> randomc(new Boundary<char>(-99, 99));

void FillArray(char size, char* array) {
    char i = N;
    while (--i > 0)
        array[i] = randomc.Standard();
}
