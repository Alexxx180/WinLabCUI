#include "task/forms/defaults/cui/screens/menu/menu.h"

#include "task/forms/defaults/cui/screens/menu/main.h"
#include "task/forms/defaults/cui/screens/menu/structure/list.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack.h"

void MenuInit() {
    MainMenu();
    ListMenu();
    QueueMenu();
    StackMenu();
}
