#include "screen/controls/menu/loop/exit.h"

#include <cstdlib>

#include "common/codes.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/lifetime/internal.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/tools/layers.h"

char ExitMenu :: LiveLoop() {
    out->Target(FOOT)->Move();
    out->Clear()->Move();
    out->Clip("status_menu_navigation");
    out->Target(MENU)->Move();

    char (Menu::*query)() = &Menu::Query;
    Await(&m_options, query, ESC);

    out->Target(FOOT)->Move();
    out->Clip("status_confirm_exit");

    return Select(ESC, ENTER);
}

void ExitMenu :: Set(Menu* options) {
    m_options = *options;
}

Menu& ExitMenu :: Get() {
    return m_options;
}

void ExitMenu :: Capture() {
    ClearScreen();
    out->Redraw()->Target(MENU)->Move();
    m_options.Expand();

    char (ExitMenu::*loop)() = &ExitMenu::LiveLoop;
    Await(this, loop, ENTER);

    ClearScreen();
    exit(OK);
}
