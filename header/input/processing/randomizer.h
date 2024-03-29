#ifndef INPUT_PROCESSING_RANDOMIZER
#define INPUT_PROCESSING_RANDOMIZER

#include "input/limiting/boundary.h"

template <typename TYPE>
struct Randomizer {
    Boundary<TYPE> limits;

    Randomizer();
    Randomizer(Boundary<TYPE> interval);

    Randomizer<TYPE> Set(Boundary<TYPE> interval);
    long Size(TYPE start, TYPE end);

    // Random implementations
    TYPE Standard();
    // Global implementation
    TYPE Random();
};

#endif
