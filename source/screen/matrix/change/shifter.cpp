#include "screen/matrix/change/shifter.h"

void Shifter :: Set(
    void (*points)(Point*),
    void (*margin)(Point*, byte),
    void (*ratio)(Point*, float)) {
    positions = points;
    shift = margin;
    stretch = ratio;
}

void Shifter :: Append(Point* from, byte append) {
    shift(from, positions(from) + append);
}

void Shifter :: Margin(Point* from, Point* to) {
    shift(from, positions(to));
}

void Shifter :: Extend(Point* basis, float relation) {
    stretch(from, relation);
}
