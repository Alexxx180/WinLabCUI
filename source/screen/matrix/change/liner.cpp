#include "screen/matrix/change/liner.h"

void Liner :: Set(
    byte (*points)(Point*),
    void (*margin)(Point*, byte)) {
    positions = points;
    shift = margin;
}

void Liner :: Append(Point* from, byte append) {
    shift(from, positions(from) + append);
}

void Liner :: Margin(Point* from, Point* to) {
    shift(from, positions(to));
}
