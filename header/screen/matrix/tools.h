#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include "screen/controls/layout/grid/grid.h"
#include "screen/controls/bar/bar.h"
#include "screen/controls/matrix/stencil.h"
#include "screen/controls/matrix/pen.h"
#include "screen/matrix/tools/layer/layer.h"

Pen* pen = Pen::ink();

Layer[2] layers;
Layer* layer = NULL;

Grid* back = NULL;
Booker* out = NULL;
Bar* status = NULL;

void SelectLayer(LayerType target) {
    layer = &layers[target];
    back = layer.back.current;
    out = layer.out.current;
    status = layer.status.current;
}

void ClearScreen() {
    system(CLEAN_COMMAND);
}

#endif
