#include "task/structure/input/menu/extra.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/matrix/types/point.h"
#include "task/structure/process/second.h"

Menu individual_menu;

void IndividualMenu() {
	Point position = { 0, 0 };
    MenuItem result, exit;

    result.SetCaption("menu_calculate");
    result.SetCommand(StartIndividual);

    exit.SetCaption("menu_exit")->SetExit();

    individual_menu.SetItems()->SetDirection(false);
    individual_menu.Add(&result)->Add(&exit)->Index(position);
}