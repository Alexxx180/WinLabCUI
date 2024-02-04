#include "task/structure/input.h"

#include <math.h>
#include <string>

#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

Menu main_menu;

char DetermineExit() {
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU);
    Await(main_menu.Query, ESC);
    Pen::ink().Target(FOOT)->Quote("status_exit");
    return Select(ESC, ENTER);
}

void Input() {
    MainMenu();
    ArrayMenu();
    Await(DetermineExit, ENTER);
}
