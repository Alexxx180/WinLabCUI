#include "input/boundary.h"

template <typename TYPE>
struct Randomizer<TYPE> {

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

}
