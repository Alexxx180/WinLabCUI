#include "task/forms/defaults/cui/screens/menu/structure/queue.h"

#include "screen/controls/menu/menuitem.h"
#include "task/forms/defaults/cui/screens/menu/structure/common.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue/fill.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue/operations.h"

ExitMenu queue_menu;

void QueueMenu() {
    MenuItem task[3];
    task[0] = FillMenu();
    task[1] = OperationsMenu();
    queue_menu.Set(CommonMenu(task));
}
