#include "task/structure/input/tasks.h"

#include "task/forms/defaults/cui/screens/menu/main.h"
#include "task/forms/defaults/cui/screens/menu/queue.h"
#include "task/forms/defaults/cui/screens/menu/stack.h"
#include "task/forms/defaults/cui/screens/menu/list.h"

void Input() { main_menu.Capture(); }

void QueueStart() { queue_menu.Capture(); }
void StackStart() { stack_menu.Capture(); }
void ListStart() { list_menu.Capture(); }
