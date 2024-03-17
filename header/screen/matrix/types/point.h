#ifndef SCREEN_MATRIX_TYPES
#define SCREEN_MATRIX_TYPES

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
