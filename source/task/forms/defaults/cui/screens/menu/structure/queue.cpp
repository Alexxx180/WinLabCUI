#include "task/forms/defaults/cui/screens/menu/structure/queue.h"

#include "screen/controls/menu/menuitem.h"
#include "task/forms/defaults/cui/screens/menu/structure/common.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue/fill.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue/operations.h"

ExitMenu queue_menu;

void QueueMenu() {
    MenuItem task[3];
    task[0] = QueueFillMenu();
    task[1] = QueueOperationsMenu();
    Menu context = CommonMenu(task);
    queue_menu.Set(&context);
}
