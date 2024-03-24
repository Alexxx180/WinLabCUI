#ifndef SCREEN_MATRIX_CHANGE_SHIFTER
#define SCREEN_MATRIX_CHANGE_SHIFTER

#include "screen/matrix/change/liner.h"

struct Shifter : public Liner {
    void (*stretch)(Point*, float);

    void Set(byte (*points)(Point*),
            void (*margin)(Point*, byte),
            void (*ratio)(Point*, float));
    void Extend(Point* basis, float relation);
};

#endif
