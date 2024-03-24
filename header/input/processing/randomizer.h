#ifndef INPUT_ADVANCED_RANDOMIZER
#define INPUT_ADVANCED_RANDOMIZER

#include <cstdlib>
#include "input/limiting/boundary.h"

template <typename TYPE>
struct Randomizer {
    Boundary<TYPE> limits;

    Randomizer() { }

    Randomizer(Boundary<TYPE> interval) {
        limits = interval;
    }

    TYPE Standard() {
        TYPE start = limits.start;
        long size = static_cast<long>(abs(start) + limits.end + 1);
        return rand() % size + start;
    }
};

#endif
