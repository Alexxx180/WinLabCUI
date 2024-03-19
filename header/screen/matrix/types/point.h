#ifndef SCREEN_MATRIX_TYPES_POINT
#define SCREEN_MATRIX_TYPES_POINT

#include "common/types.h"

struct Point {
    byte X, Y;

    void Swap() {
        byte T;
        T = X;
        X = Y;
        Y = T;
    }
};

#endif
