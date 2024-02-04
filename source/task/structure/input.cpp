#include "task/structure/input.h"

#include <math.h>
#include <string>

#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

Verifier<short>* numeric = new Verifier<short>();

void SetStatusSignal() {
    numeric->status.Server(FOOT)->Signal(Pen::ink().Feedback());
}

MenuItem main_menu;

void DetermineExit() {
    Pen::ink().Target(FOOT)->Quote("status_menu_navigation");
    Pen::ink().Target(MENU);
    Await(main_menu.Query, ESC);
    Pen::ink().Target(FOOT)->Quote("status_exit");
    return Select(ESC, ENTER);
}

void Input() {
    SetStatusSignal();
    MainMenu();
    ArrayMenu();
    Await(DetermineExit, ENTER);
}

void MainMenu() {
    MenuItem task1, task2;
    task1.SetCommand(ArraySort)->SetCaption("menu_array_sort");
    task2.SetCommand(Individual)->SetCaption("menu_individual");

    MenuItem tasks, exit;
    tasks.SetItems()->SetOrientation(false);
    tasks.Add(task1)->Add(task2);
    tasks.SetCaption("menu_tasks");

    exit.SetExit()->SetCaption("menu_exit");

    main_menu.SetItems()->SetOrientation(true);
    main_menu.Add(tasks)->Add(exit);
    
}
