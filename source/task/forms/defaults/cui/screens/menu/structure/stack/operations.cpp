#include "task/forms/defaults/cui/screens/menu/structure/stack/operations.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/stack.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/operations/view.h"

MenuItem OperationsMenu() {
    MenuItem operations, o[4];
    o[0] = ViewMenu();
    o[1].SetCommand(new Label("menu_operations_add"), Append);
    o[2].SetCommand(new Label("menu_operations_delete"), Remove);
    o[3].SetCommand(new Label("menu_stack_minimal"), Minimal);

    operations.SetItems(new Label("menu_operations"));
    for (char i = 0; i < 4; i++) operations.Add(&o[i]);
    return operations;
}
