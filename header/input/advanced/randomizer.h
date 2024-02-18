#ifndef INPUT_ADVANCED_RANDOMIZER
#define INPUT_ADVANCED_RANDOMIZER

#include "input/boundary.h"

template <typename TYPE>
struct Randomizer {
    Boundary<TYPE> limits;

    Randomizer() { }

    Randomizer(Boundary<TYPE> interval) {
        limits = interval;
    }

    TYPE Standard() {
        TYPE start = limits.start;
        long size = limits.start + limits.end + 1;

        return rand() % size + start;
    }
};

#endif
