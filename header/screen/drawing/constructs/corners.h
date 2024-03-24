#ifndef SCREEN_DRAWING_CONSTRUCTS_CORNERS
#define SCREEN_DRAWING_CONSTRUCTS_CORNERS

#include "screen/drawing/constructs/outlines/separator.h"
#include "screen/drawing/constructs/outlines/borders.h"
#include "screen/drawing/constructs/outlines/angles.h"

struct Corners {
    Separator Standing, Lying;
    Borders Vertical, Horizontal;
    Angles Top, Bottom;
};

#endif
