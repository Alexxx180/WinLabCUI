#ifndef SCREEN_MATRIX_TYPES_CHANGE_SHIFTER
#define SCREEN_MATRIX_TYPES_CHANGE_SHIFTER

#include "screen/matrix/types/change/liner.h"

struct Shifter : public Liner {
    axis_extend stretch;

    void Set(point_extract points, axis_shift margin, axis_extend ratio);
    void Extend(Point* basis, float relation);
};

#endif
