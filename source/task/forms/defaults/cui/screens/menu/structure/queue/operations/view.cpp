#include "task/forms/defaults/cui/screens/menu/structure/queue/operations/view.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/queue.h"

MenuItem QueueViewMenu() {
    MenuItem ops, v[3];
    v[0].SetCommand(new Label("menu_first"), QueueToFirst);
    v[1].SetCommand(new Label("menu_operations_search"), QueueJumpToSearch);
    v[2].SetCommand(new Label("menu_last"), QueueToLast);

    ops.SetItems(new Label("menu_operations_view"));
    for (char i = 0; i < 3; i++) ops.Add(&v[i]);
    return ops;
}
