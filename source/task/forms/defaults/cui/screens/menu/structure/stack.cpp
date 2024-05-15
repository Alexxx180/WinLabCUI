#include "task/forms/defaults/cui/screens/menu/structure/stack.h"

#include "screen/controls/menu/menuitem.h"
#include "task/forms/defaults/cui/screens/menu/structure/common.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/fill.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/operations.h"

ExitMenu stack_menu;

void ListMenu() {
    MenuItem task[3];
    task[0] = FillMenu();
    task[1] = OperationsMenu();
    stack_menu.Set(CommonMenu(task));
}