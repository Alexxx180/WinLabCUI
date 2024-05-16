#include "task/forms/defaults/cui/screens/menu/structure/stack/operations/view.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/stack.h"

MenuItem ViewMenu() {
    MenuItem ops, v[2];
    v[0].SetCommand(new Label("menu_operations_search"), JumpToSearch);
    v[1].SetCommand(new Label("menu_last"), ToLast);

    ops.SetItems(new Label("menu_operations_view"));
    for (char i = 0; i < 2; i++) ops.Add(&v[i]);
    return ops;
}
