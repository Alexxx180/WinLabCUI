#include "screen/matrix/change/stapler.h"

void Stapler :: Set(
    void (*line)(Point*, byte),
    void (*points)(Point*, byte)) {
    progress = line;
    pins = points;
}
