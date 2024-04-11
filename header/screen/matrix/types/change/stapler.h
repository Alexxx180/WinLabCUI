#ifndef SCREEN_MATRIX_TYPES_CHANGE_STAPLER
#define SCREEN_MATRIX_TYPES_CHANGE_STAPLER

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/change/invokations.h"

struct Stapler {
    axis_shift progress, pins;

    void Set(axis_shift line, axis_shift points);
};

#endif
