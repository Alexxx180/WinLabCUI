#include "task/forms/defaults/cui/screens/menu/structure/stack/fill.h"

#include "screen/controls/menu/field/label.h"
#include "task/structure/process/structures/menu/stack.h"

MenuItem StackFillMenu() {
    MenuItem stack, q[2];
    q[0].SetCommand(new Label("menu_fill_randomized"), StackRandomized);
    q[1].SetCommand(new Label("menu_fill_reset"), StackReset);

    stack.SetItems(new Label("menu_stack"))->Vertical(true);
    for (char i = 0; i < 2; i++) stack.Add(&q[i]);
    return stack;
}
