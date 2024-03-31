#include "task/structure/output/sort/output/restore.h"

#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

void RestoreOutput() {
    SelectLayer(SCREEN);
    out->Redraw()->Target(FOOT)->Move();
    out->Clip("status_menu_navigation");
    out->Target(MENU);
}
