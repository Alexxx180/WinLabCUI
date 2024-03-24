#include "screen/matrix/change/shifter.h"

void Shifter :: Set(
    byte (*points)(Point*),
    void (*margin)(Point*, byte),
    void (*ratio)(Point*, float)) {
    Liner::Set(points, margin);
    stretch = ratio;
}

void Shifter :: Extend(Point* basis, float relation) {
    stretch(basis, relation);
}
