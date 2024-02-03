#ifndef SCREEN_ART_CONTROLS_BAR_TYPES_CORNERS
#define SCREEN_ART_CONTROLS_BAR_TYPES_CORNERS

#include "screen/art/controls/bar/types/separator.h"

struct Borders {
    wchar_t Front, Back;
};

struct Corners {
    Separator Standing, Lying;
    Borders Vertical, Horizontal;
    Angles Top, Bottom;
};

#endif
