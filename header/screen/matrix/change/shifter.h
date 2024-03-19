#ifndef SCREEN_MATRIX_CHANGE_SHIFTER
#define SCREEN_MATRIX_CHANGE_SHIFTER

#include "common/types.h"
#include "screen/matrix/types/point.h"

struct Shifter {
    byte (*positions)(Point*);
    void (*shift)(Point*, byte);
    void (*stretch)(Point*, float);

    void Set(void (*points)(Point*), void (*margin)(Point*, byte), void (*ratio)(Point*, float));
    void Append(Point* from, byte append);
    void Margin(Point* from, Point* to);
    void Extend(Point* basis, float relation);
};

#endif
