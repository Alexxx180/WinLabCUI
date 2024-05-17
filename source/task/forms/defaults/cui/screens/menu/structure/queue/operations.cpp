#include "task/forms/defaults/cui/screens/menu/structure/queue/operations.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/queue.h"
#include "task/forms/defaults/cui/screens/menu/structure/queue/operations/view.h"

MenuItem QueueOperationsMenu() {
    MenuItem operations, o[3];
    o[0] = QueueViewMenu();
    o[1].SetCommand(new Label("menu_operations_add"), QueueAppend);
    o[2].SetCommand(new Label("menu_operations_delete"), QueueRemove);

    operations.SetItems(new Label("menu_operations"));
    for (char i = 0; i < 3; i++) operations.Add(&o[i]);
    return operations;
}
