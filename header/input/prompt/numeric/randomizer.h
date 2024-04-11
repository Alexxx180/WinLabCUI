#ifndef INPUT_PROCESSING_RANDOMIZER
#define INPUT_PROCESSING_RANDOMIZER

#include "input/feedback/limiting/boundary.h"

template <typename TYPE>
struct Randomizer {
    Boundary<TYPE>* limits;

    Randomizer() {}
    Randomizer(Boundary<TYPE>& interval) { Set(interval); }
    Randomizer<TYPE>* Set(Boundary<TYPE>& interval) {
        limits = &interval;
        return this;
    }

    long Size(TYPE start, TYPE end) {
        return static_cast<long>(abs(start) + end + 1);
    }

    // Random implementations
    TYPE Standard() {
        long size = Size(limits->start, limits->end);
        return rand() % size + limits->start;
    }

    // Global implementation
    TYPE Random() {
        return Standard();
    }
};

#endif
