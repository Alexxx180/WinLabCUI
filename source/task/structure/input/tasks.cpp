#include "task/structure/input/tasks.h"

#include "screen/interaction.h"
#include "screen/matrix/pen.h"
#include "screen/art/controls/menu/menu.h"
#include "task/structure/input/menu/main.h"
#include "task/structure/input/menu/array.h"
#include "task/structure/input/menu/individual.h"

char DetermineExit(Menu* menu) {
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU);

    char (Menu::*query)() = &Menu::Query;
    Await(menu, query, ESC);

    Pen::ink().Target(FOOT)->Quote("status_exit");
    return Select(ESC, ENTER);
}

char MainMenuLoop() { return DetermineExit(&main_menu); }

char ArrayMenuLoop() { return DetermineExit(&array_menu); }

char IndividualMenuLoop() {
    return DetermineExit(&individual_menu);
}

void ArraySort() {
    Pen::ink().Redraw();
    array_menu.Expand();
    Await(ArrayMenuLoop, ENTER);
}

void Individual() {
    Pen::ink().Redraw();
    individual_menu.Expand();
    Await(IndividualMenuLoop, ENTER);
}

void Input() {
    Pen::ink().Redraw();
    main_menu.Expand();
    Await(MainMenuLoop, ENTER);
}
