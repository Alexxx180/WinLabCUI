#include "screen/matrix/tools.h"

#include <cstdlib>

const char layers_count = 2;

Layer layers[layers_count];
Layer* out = NULL;

void ClearScreen() {
    system(CLEAN_COMMAND);
}

void SelectLayer(Layers target) {
    out = &layers[target];
}

void RetargetLayers(Fragments target) {
    char i = layers_count;
    while (--i >= 0) {
        layers[i].out.Target(target);
        layers[i].back.Target(target);
        layers[i].status.Target(target);
    }
}
