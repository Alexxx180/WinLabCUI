#include "task/forms/defaults/cui/screens/menu/structure/list/fill.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/list.h"

MenuItem FillMenu() {
    MenuItem list, l[3];

    l[0].SetCommand(new Label("menu_list_ordered"), Order);
    l[1].SetCommand(new Label("menu_fill_randomized"), Randomized);
    l[2].SetCommand(new Label("menu_fill_reset"), Reset);

    list.SetItems(new Label("menu_list"));
    for (char i = 0; i < 3; i++) list.Add(&l[i]);

    return list;
}
