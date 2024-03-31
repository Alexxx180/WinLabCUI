#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include "screen/matrix/tools/layers.h"
#include "screen/matrix/tools/layer/layer.h"

void SelectLayer(Layers target);
void RetargetLayers(Fragments target);
void ClearScreen();

extern Layer layers[2];
extern Layer* out;

#endif
