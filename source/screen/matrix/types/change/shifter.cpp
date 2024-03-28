#include "screen/matrix/types/change/shifter.h"

void Shifter :: Set(point_extract points, axis_shift margin, axis_extend ratio) {
    Liner::Set(points, margin);
    stretch = ratio;
}

void Shifter :: Extend(Point* basis, float relation) {
    stretch(basis, relation);
}
