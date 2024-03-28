#ifndef SCREEN_MATRIX_TOOLS_LAYER_LAYER
#define SCREEN_MATRIX_TOOLS_LAYER_LAYER

#include "screen/matrix/tools/layer/fragment.h"
#include "screen/controls/matrix/screen.h"
#include "screen/controls/bar/bar.h"

struct Layer {
    Fragment<Grid> back;
    Fragment<Stencil> out;
    Fragment<Bar> status;

    void Add(Screen* screen);
    void Target(byte current);
    void Redraw();
};

#endif
