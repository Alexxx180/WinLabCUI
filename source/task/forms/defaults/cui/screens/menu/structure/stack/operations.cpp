#include "task/forms/defaults/cui/screens/menu/structure/stack/operations.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/stack.h"
#include "task/forms/defaults/cui/screens/menu/structure/stack/operations/view.h"

MenuItem StackOperationsMenu() {
    MenuItem operations, o[4];
    o[0] = StackViewMenu();
    o[1].SetCommand(new Label("menu_operations_add"), StackAppend);
    o[2].SetCommand(new Label("menu_operations_delete"), StackRemove);
    o[3].SetCommand(new Label("menu_stack_minimal"), StackMinimal);

    operations.SetItems(new Label("menu_operations"))->Vertical(true);
    for (char i = 0; i < 4; i++) operations.Add(&o[i]);
    return operations;
}
