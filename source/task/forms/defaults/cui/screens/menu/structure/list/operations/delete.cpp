#include "task/forms/defaults/cui/screens/menu/structure/list/operations/delete.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/list.h"

MenuItem DeleteMenu() {
    MenuItem ops, d[3];
    d[0].SetCommand(new Label("menu_first"), RemoveFirst);
    d[1].SetCommand(new Label("menu_operations_search"), RemoveAt);
    d[2].SetCommand(new Label("menu_last"), RemoveLast);

    ops.SetItems(new Label("menu_operations_delete_recurse"));
    for (char i = 0; i < 3; i++) ops.Add(&d[i]);
    return ops;
}
