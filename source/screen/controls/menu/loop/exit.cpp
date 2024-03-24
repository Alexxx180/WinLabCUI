#include "screen/controls/menu/loop/exit.h"

#include <cstdlib>

#include "common/codes.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char ExitMenu :: LiveLoop() {
    layer->Target(FOOT);
    pen->Clip("status_menu_navigation");
    layer->Target(MENU);
    out->Move();

    Await(&m_options, &Menu::Query, ESC);

    layer->Target(FOOT);
    pen->Clip("status_confirm_exit");

    return Select(ESC, ENTER);
}

void ExitMenu :: Set(Menu* options) {
    m_options = *options;
}

void ExitMenu :: Capture() {
    ClearScreen();
    layer->Redraw();
    layer->Target(MENU);
    out->Move();
    options->Expand();
    Await(this, &ExitMenu::LiveLoop, ENTER);
    ClearScreen();
    exit(OK);
}
