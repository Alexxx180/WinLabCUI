#ifndef SCREEN_MATRIX_TYPES_CHANGE_LINER
#define SCREEN_MATRIX_TYPES_CHANGE_LINER

#include "common/types.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/change/invokations.h"

struct Liner {
    point_extract extract;
    axis_shift shift;

    void Set(point_extract points, axis_shift margin);
    void Append(Point* from, byte append);
    void Subtract(Point* from, byte subtract);
    void Margin(Point* from, Point* to);
};

#endif
