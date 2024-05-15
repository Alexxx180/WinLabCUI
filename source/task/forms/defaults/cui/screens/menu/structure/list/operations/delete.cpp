#include "task/forms/defaults/cui/screens/menu/structure/list/operations/delete.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/list.h"

MenuItem DeleteMenu() {
    MenuItem ops, d[3];
    d[0].SetCommand(new Label("menu_list_delete_first"), RemoveFirst);
    d[1].SetCommand(new Label("menu_list_delete_at"), RemoveAt);
    d[2].SetCommand(new Label("menu_list_delete_last"), RemoveLast);

    ops.SetItems(new Label("menu_operations_delete"));
    for (char i = 0; i < 3; i++) ops.Add(d[i]);
    return ops;
}
