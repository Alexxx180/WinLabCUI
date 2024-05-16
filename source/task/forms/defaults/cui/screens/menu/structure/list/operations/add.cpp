#include "task/forms/defaults/cui/screens/menu/structure/list/operations/add.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/list.h"

MenuItem AddMenu() {
    MenuItem ops, a[4];
    a[0].SetCommand(new Label("menu_first"), InsertFirst);
    a[1].SetCommand(new Label("menu_before"), InsertBefore);
    a[2].SetCommand(new Label("menu_after"), InsertAfter);
    a[3].SetCommand(new Label("menu_last"), InsertLast);

    ops.SetItems(new Label("menu_operations_add_recurse"));
    for (char i = 0; i < 4; i++) ops.Add(&a[i]);
    return ops;
}
