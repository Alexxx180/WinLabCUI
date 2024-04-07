#include "task/forms/defaults/cui/tools/layers.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void InitLayers() {
    RetargetLayers(MAIN);
    SelectLayer(SCREEN);

    out->Target(MENU);
    out->Size(1)->Span(1);
}
