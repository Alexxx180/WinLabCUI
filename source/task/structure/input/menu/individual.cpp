#include "task/structure/input/menu/array.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "task/structure/input/individual/task.h"

Menu individual_menu;

void IndividualMenu() {
    MenuItem result, exit;

    result.SetCaption("menu_individual_start");
    result.SetCommand(StartIndividual);

    exit.SetCaption("menu_exit")->SetExit();

    array_menu.SetItems()->SetOrientation(false);
    array_menu.Add(&array)->Add(&exit);
}
