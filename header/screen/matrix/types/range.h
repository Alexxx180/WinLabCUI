#ifndef SCREEN_MATRIX_TYPES_RANGE
#define SCREEN_MATRIX_TYPES_RANGE

#include "screen/matrix/types/point.h"

struct Range {
    Point P1, P2;

    Range SwapXY();
    Range Swap();
    Range SwapSizes();

    byte SumX();
    byte SumY();
};

#endif
