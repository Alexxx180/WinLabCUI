#ifndef SCREEN_CONTROLS_MATRIX_SCREEN
#define SCREEN_CONTROLS_MATRIX_SCREEN

#include "screen/controls/layout/grid/grid.h"
#include "screen/controls/matrix/stencil.h"

struct Screen {
    Grid* back = NULL;
    Stencil* out = NULL;
};

#endif
