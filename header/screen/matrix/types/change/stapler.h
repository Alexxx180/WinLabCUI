#ifndef SCREEN_MATRIX_CHANGE_STAPLER
#define SCREEN_MATRIX_CHANGE_STAPLER

#include "common/types.h"
#include "screen/matrix/types/point.h"

struct Stapler {
    void (*progress)(Point*, byte);
    void (*pins)(Point*, byte);

    void Set(void (*line)(Point*, byte), void (*points)(Point*, byte));
};

#endif
