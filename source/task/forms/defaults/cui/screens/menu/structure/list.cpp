#include "task/forms/defaults/cui/screens/menu/individual.h"

#include "screen/controls/menu/loop/exit.h"
#include "screen/controls/menu/menu.h"
#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/structure/process/individual/individual.h"

ExitMenu list_menu;

void ListMenu() {
    Menu context;
    MenuItem result, exit;
    MenuItem l[4];

    std::string caption = "menu_calculate";
    result.SetCommand(new Label(caption), StartIndividual);
    l[0].SetCommand(new Label(), );

    exit.SetExit(new Label("menu_exit"));

    context.SetItems()->Add(&result)->Add(&exit);
    context.Index({ 0, 0 });

    individual_menu.Set(&context);
}
