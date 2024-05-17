#include "task/forms/defaults/cui/screens/menu/structure/list/operations.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/list.h"
#include "task/forms/defaults/cui/screens/menu/structure/list/operations/add.h"
#include "task/forms/defaults/cui/screens/menu/structure/list/operations/delete.h"

MenuItem ListOperationsMenu() {
    MenuItem operations, o[3];
    o[0].SetCommand(new Label("menu_operations_search"), ListJumpToSearch);
    o[1] = ListAddMenu();
    o[2] = ListDeleteMenu();

    operations.SetItems(new Label("menu_operations"));
    for (char i = 0; i < 3; i++) operations.Add(&o[i]);
    return operations;
}
