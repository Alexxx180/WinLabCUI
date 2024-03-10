#include "task/structure/input/common/data.h"

#include "input/boundary.h"
#include "input/advanced/randomizer.h"

Boundary<char> RandomLimits() {
    Boundary<char> limits(-99, 99);
    return limits;
}

Randomizer<char> randomc = { RandomLimits() };

void FillArray(char size, char* array) {
    while (--size >= 0) array[size] = randomc.Standard();
}
