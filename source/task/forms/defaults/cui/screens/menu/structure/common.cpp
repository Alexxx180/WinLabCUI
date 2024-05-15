#include "task/forms/defaults/cui/screens/menu/structure/common.h"

#include "screen/controls/menu/menu.h"
#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"

void CommonMenu(MenuItem& task[3]) {
    Menu context;
    task[2].SetExit(new Label("menu_exit"));

    context.SetItems();
    for (char i = 0; i < 3; i++)
        context.Add(&task[i]);
    context.Index({ 0, 0 });

    return context;
}
