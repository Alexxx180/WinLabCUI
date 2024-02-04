#include "task/structure/input/menu/main.h"

#include "task/markdown/debug.cpp"
#include "task/structure/input/menu/navigation.h"
#include "task/structure/input/menu/array.h"
#include "screen/interaction.h"

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

    main_menu.SetItems()->SetOrientation(true);
    main_menu.Add(&tasks)->Add(&exit);
    
}
