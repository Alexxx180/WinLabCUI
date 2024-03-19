#ifndef SCREEN_DRAWING_TYPES_CONSTRUCTS_CORNERS
#define SCREEN_DRAWING_TYPES_CONSTRUCTS_CORNERS

#include "screen/drawing/types/constructs/outlines/separator.h"
#include "screen/drawing/types/constructs/outlines/borders.h"
#include "screen/drawing/types/constructs/outlines/angles.h"

struct Corners {
    Separator Standing, Lying;
    Borders Vertical, Horizontal;
    Angles Top, Bottom;
};

#endif
