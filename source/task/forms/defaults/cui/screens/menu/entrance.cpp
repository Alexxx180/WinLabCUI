#include "task/structure/input/menu/entrance.h"

#include "screen/controls/menu/loop/exit.h"
#include "screen/controls/menu/menu.h"
#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/structure/input/tasks.h"

ExitMenu main_menu;

void MainMenu() {
    Menu context;
    MenuItem tasks, exit;
    MenuItem task1, task2;

    task1.SetCommand(new Label("menu_array_sort"), ArraySort);
    task2.SetCommand(new Label("menu_individual"), Individual);

    tasks.SetItems(new Label("menu_header"))->Vertical(true);
    tasks.Add(&task1)->Add(&task2);

    exit.SetExit(new Label("menu_exit"));

    context.SetItems()->Add(&tasks)->Add(&exit);
    context.Index({ 0, 0 });

    main_menu.Set(&context);
}
