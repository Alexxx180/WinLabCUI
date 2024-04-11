#include "screen/matrix/types/change/liner.h"

void Liner :: Set(point_extract points, axis_shift margin) {
    extract = points;
    shift = margin;
}

void Liner :: Append(Point* from, byte append) {
    shift(from, extract(from) + append);
}

void Liner :: Subtract(Point* from, byte append) {
    shift(from, extract(from) - append);
}

void Liner :: Margin(Point* from, Point* to) {
    shift(from, extract(to));
}
