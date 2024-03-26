#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include "screen/controls/matrix/stencil.h"
#include "screen/controls/matrix/pen.h"
#include "screen/controls/bar/bar.h"
#include "screen/controls/layout/grid/grid.h"
#include "screen/matrix/tools/layers.h"
#include "screen/matrix/tools/layer/layer.h"

void SelectLayer(Layers target);
void ClearScreen();

extern Layer layers[2];
extern Layer* layer;

extern Pen* pen;

extern Stencil* out;
extern Grid* back;
extern Bar* status;

#endif
