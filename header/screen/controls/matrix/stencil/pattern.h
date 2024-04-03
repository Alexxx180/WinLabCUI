#ifndef SCREEN_CONTROLS_MATRIX_STENCIL_PATTERN
#define SCREEN_CONTROLS_MATRIX_STENCIL_PATTERN

#include "screen/matrix/types/point.h"

class Pattern {
    public:
        void Clear(Point* cursor, short width);
        void Decoration(Point* cursor, short width);
        void Pipe(Point* cursor);
};

#endif
