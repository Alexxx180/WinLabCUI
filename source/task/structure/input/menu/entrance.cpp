#include "task/structure/input/menu/entrance.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/content/label.h"
#include "task/structure/input/tasks.h"

Menu main_menu;

void MainMenu() {
    MenuItem tasks, exit;
    MenuItem task1, task2;

    task1.SetCommand(new Label("menu_array_sort"), ArraySort);
    task2.SetCommand(new Label("menu_individual"), Individual);

    tasks.SetItems(new Label("menu_header"))->Vertical(true);
    tasks.Add(&task1)->Add(&task2);

    exit.SetExit(new Label("menu_exit"));

    main_menu.SetItems()->Add(&tasks)->Add(&exit);
    main_menu.Index({ 0, 0 });
}
