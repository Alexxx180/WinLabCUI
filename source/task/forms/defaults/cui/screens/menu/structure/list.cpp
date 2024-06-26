#include "task/forms/defaults/cui/screens/menu/structure/list.h"

#include "screen/controls/menu/menuitem.h"
#include "task/forms/defaults/cui/screens/menu/structure/common.h"
#include "task/forms/defaults/cui/screens/menu/structure/list/fill.h"
#include "task/forms/defaults/cui/screens/menu/structure/list/operations.h"

ExitMenu list_menu;

void ListMenu() {
    MenuItem task[3];
    task[0] = ListFillMenu();
    task[1] = ListOperationsMenu();
    Menu context = CommonMenu(task);
    list_menu.Set(&context);
}
