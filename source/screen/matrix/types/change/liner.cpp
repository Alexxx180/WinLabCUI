#include "screen/matrix/change/liner.h"

void Liner :: Set(point_extract points, axis_shift margin) {
    positions = points;
    shift = margin;
}

void Liner :: Append(Point* from, byte append) {
    shift(from, positions(from) + append);
}

void Liner :: Margin(Point* from, Point* to) {
    shift(from, positions(to));
}
