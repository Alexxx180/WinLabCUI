#include "task/structure/input/menu/main.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "task/structure/input/tasks.h"

Menu main_menu;

void MainMenu() {
    MenuItem task1, task2;

    task1.SetCommand(ArraySort)->SetCaption("menu_array_sort");
    task2.SetCommand(Individual)->SetCaption("menu_individual");

    MenuItem tasks, exit;

    tasks.SetItems()->SetOrientation(false);
    tasks.Add(&task1)->Add(&task2);
    tasks.SetCaption("menu_tasks");

    exit.SetExit()->SetCaption("menu_exit");

    main_menu.SetItems()->SetOrientation(false);
    main_menu.Add(&tasks)->Add(&exit);
}
