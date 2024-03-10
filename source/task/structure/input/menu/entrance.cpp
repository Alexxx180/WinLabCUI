#include "task/structure/input/menu/entrance.h"

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/matrix/types/point.h"
#include "task/structure/input/tasks.h"

Menu main_menu;

void MainMenu() {
	Point position = { 0, 0 };
    MenuItem task1, task2;

    task1.SetCommand(ArraySort)->SetCaption("menu_array_sort");
    task2.SetCommand(Individual)->SetCaption("menu_individual");

    MenuItem tasks, exit;

    tasks.SetItems()->SetDirection(true);
    tasks.Add(&task1)->Add(&task2);
    tasks.SetCaption("menu_header");

    exit.SetExit()->SetCaption("menu_exit");

    main_menu.SetItems()->SetDirection(false);
    main_menu.Add(&tasks)->Add(&exit)->Index(position);
}
