#include "task/forms/defaults/cui/screens/menu/main.h"

#include "screen/controls/menu/menu.h"
#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/forms/defaults/cui/screens/menu/main/structure.h"
#include "task/forms/defaults/cui/screens/menu/main/practice.h"

ExitMenu main_menu;

void MainMenu() {
    Menu context;
    MenuItem task[3];
    task[0] = StructureMenu();
    task[1] = PracticeMenu();
    task[2].SetExit(new Label("menu_exit"));

    context.SetItems();
    for (char i = 0; i < 3; i++)
        context.Add(&task[i]);
    context.Index({ 0, 0 });

    main_menu.Set(&context);
}
