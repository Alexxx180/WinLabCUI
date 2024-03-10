#include "task/structure/input/tasks.h"

#include "screen/interaction.h"
#include "screen/matrix/pen.h"
#include "screen/art/controls/menu/menu.h"
#include "task/structure/input/menu/entrance.h"
#include "task/structure/input/menu/array.h"
#include "task/structure/input/menu/extra.h"

Menu* current_menu = NULL;

char DetermineExit() {
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU)->screen->Move();

    char (Menu::*query)() = &Menu::Query;
    Await(current_menu, query, ESC);

    Pen::ink().Target(FOOT)->Quote("status_confirm_exit");
    return Select(ESC, ENTER);
}

void MenuLoop(Menu* menu) {
	Pen::ink().Redraw();
	Pen::ink().Target(MENU)->screen->Move();
	current_menu = menu;
    current_menu->Expand();
    Await(DetermineExit, ENTER);
}

void ArraySort() { MenuLoop(&array_menu); }
void Individual() { MenuLoop(&individual_menu); }
void Input() { MenuLoop(&main_menu); }

void MenuInit() {
	MainMenu();
	ArrayMenu();
	IndividualMenu();
}
