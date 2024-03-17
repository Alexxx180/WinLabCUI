#include "task/structure/input/menu/extra.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/content/label.h"
#include "task/structure/process/second.h"

Menu individual_menu;

void IndividualMenu() {
    MenuItem result, exit;

    std::string caption = "menu_calculate";
    result.SetCommand(new Label(caption), StartIndividual);

    exit.SetExit(new Label("menu_exit"));

    individual_menu.SetItems()->Add(&result)->Add(&exit);
    individual_menu.Index({ 0, 0 });
}
