#include "screen/matrix/change/stapler.h"

void Stapler :: Set(axis_shift line, axis_shift points) {
    progress = line;
    pins = points;
}
