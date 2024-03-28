#include "screen/matrix/tools.h"

#include <cstdlib>

Layer layers[2];
Layer* layer = NULL;

Pen* pen = NULL;

Stencil* out = NULL;
Grid* back = NULL;
Bar* status = NULL;

void SetPenInstance() {
    pen = Pen::ink();
}

void ClearScreen() {
    system(CLEAN_COMMAND);
}

void SelectLayer(Layers target) {
    layer = &layers[target];
    back = layer->back.current;
    out = layer->out.current;
    status = layer->status.current;
}
