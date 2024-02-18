#include "task/structure/input/menu/individual.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "task/structure/process/individual.h"

Menu individual_menu;

void IndividualMenu() {
    MenuItem result, exit;

    result.SetCaption("menu_individual_start");
    result.SetCommand(StartIndividual);

    exit.SetCaption("menu_exit")->SetExit();

    individual_menu.SetItems()->SetDirection(false);
    individual_menu.Add(&result)->Add(&exit);
}
