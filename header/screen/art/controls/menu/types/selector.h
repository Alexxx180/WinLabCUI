#ifndef SCREEN_ART_CONTROLS_MENU_TYPES_SELECTOR
#define SCREEN_ART_CONTROLS_MENU_TYPES_SELECTOR

#include "screen/matrix/types/point.h"

struct Selector {
    Point Position, Direction = { 1, 0 };
    unsigned char Index;
};

#endif
