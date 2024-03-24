#ifndef SCREEN_MATRIX_CHANGE_LINER
#define SCREEN_MATRIX_CHANGE_LINER

#include "common/types.h"
#include "screen/matrix/types/point.h"

struct Liner {
    byte (*positions)(Point*);
    void (*shift)(Point*, byte);

    void Set(byte (*points)(Point*),
            void (*margin)(Point*, byte));
    void Append(Point* from, byte append);
    void Margin(Point* from, Point* to);
};

#endif
