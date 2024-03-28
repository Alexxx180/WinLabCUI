#include "task/forms/screen/layers.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void InitLayers() {
    SelectLayer(SCREEN);
    layer->Target(MENU);
    out->Size(1)->Span(1);
}

void InitPen() {
    pen = Pen::ink();
}
