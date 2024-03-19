#ifndef SCREEN_CONTROLS_MENU_TYPES_SELECTOR
#define SCREEN_CONTROLS_MENU_TYPES_SELECTOR

#include "common/types.h"
#include "screen/matrix/types/point.h"

struct Selector {
    Point Position, Direction = { 1, 0 };
    byte Index;
};

#endif
