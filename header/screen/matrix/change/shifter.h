#ifndef SCREEN_MATRIX_CHANGE_SHIFTER
#define SCREEN_MATRIX_CHANGE_SHIFTER

#include "common/types.h"

struct Shifter {
    byte (*positions)(Point*);
    void (*shift)(Point*, byte);
    void (*stretch)(Point*, float);

    void Set(void (*points)(Point*),
            void (*margin)(Point*, byte),
            void (*ratio)(Point*, float)) {
        positions = points;
        shift = margin;
        stretch = ratio;
    }

    void Append(Point* from, byte append) {
        shift(from, positions(from) + append);
    }

    void Margin(Point* from, Point* to) {
        shift(from, positions(to));
    }

    void Extend(Point* basis, float relation) {
        stretch(from, relation);
    }
};

#endif
