#include "task/structure/input/tasks.h"

#include "task/forms/defaults/cui/screens/menu/main.h"
#include "task/forms/defaults/cui/screens/menu/structures/queue.h"
#include "task/forms/defaults/cui/screens/menu/structures/stack.h"
#include "task/forms/defaults/cui/screens/menu/structures/list.h"

#include "task/form/defaults/cui/screens/templates/list.h"
#include "task/form/defaults/cui/screens/templates/queue.h"
#include "task/form/defaults/cui/screens/templates/stack.h"

void Input() { main_menu.Capture(); }

void QueueStart() {
    QueueInfo();
    queue_menu.Capture();
}

void StackStart() {
    StackInfo();
    stack_menu.Capture();
}

void ListStart() {
    ListInfo();
    list_menu.Capture();
}
