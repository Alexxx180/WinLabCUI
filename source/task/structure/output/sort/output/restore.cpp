#include "task/structure/output/sort/output/restore.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void RestoreOutput() {
    SelectLayer(SCREEN);

    layer->Redraw();
    layer->Target(FOOT);
    pen->Clip("status_menu_navigation");
    layer->Target(MENU);
}
