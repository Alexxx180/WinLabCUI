#include "task/forms/defaults/cui/screens/menu/structure/stack.h"

#include "screen/controls/menu/menuitem.h"
#include "task/forms/defaults/cui/screens/menu/structure/common.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/fill.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/operations.h"

ExitMenu stack_menu;

void StackMenu() {
    MenuItem task[3];
    task[0] = FillMenu();
    task[1] = OperationsMenu();
    Menu context = CommonMenu(task);
    stack_menu.Set(&context);
}
