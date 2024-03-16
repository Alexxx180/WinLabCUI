#include "task/structure/input/tasks.h"

#include <cstdlib>

#include "common/codes.h"
#include "screen/interaction.h"
#include "screen/matrix/pen.h"
#include "screen/art/controls/menu/menu.h"
#include "task/structure/input/menu/entrance.h"
#include "task/structure/input/menu/array.h"
#include "task/structure/input/menu/extra.h"

char DetermineExit(Menu* menu) {
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU)->screen->Move();

    char (Menu::*query)() = &Menu::Query;
    Await(menu, query, ESC);

    Pen::ink().Target(FOOT)->Quote("status_confirm_exit");
    return Select(ESC, ENTER);
}

void MenuLoop(Menu* menu, char (*determine)()) {
	Pen::ink().Redraw();
	Pen::ink().Target(MENU)->screen->Move();
    menu->Expand();
	wprintf(L"SOFT-EXIT");
    Await(determine, ENTER);
	wprintf(L"EXIT");
	Pen::ink().Reset();
	exit(OK);
}

char ArrayExit() { return DetermineExit(&array_menu); }
void ArraySort() { MenuLoop(&array_menu, ArrayExit); }

char IndividualExit() { return DetermineExit(&individual_menu); }
void Individual() { MenuLoop(&individual_menu, IndividualExit); }

char MainExit() { return DetermineExit(&main_menu); }
void Input() { MenuLoop(&main_menu, MainExit); }

void MenuInit() {
	MainMenu();
	ArrayMenu();
	IndividualMenu();
	Pen::ink().Target(MENU)->screen->Size(1)->Span(1);
}
