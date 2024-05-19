#include "task/structure/input/tasks.h"

#include "task/forms/defaults/cui/screens/menu/main.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack.h"
#include "task/forms/defaults/cui/screens/menu/structure/list.h"

#include "task/forms/defaults/cui/screens/templates/list.h"
#include "task/forms/defaults/cui/screens/templates/queue.h"
#include "task/forms/defaults/cui/screens/templates/stack.h"

#include "screen/interaction/interaction.h"

void Input() { main_menu.Capture(); }

void QueueStart() { queue_menu.Capture(); }

void StackStart() { stack_menu.Capture(); }

void ListStart() { list_menu.Capture(); }
