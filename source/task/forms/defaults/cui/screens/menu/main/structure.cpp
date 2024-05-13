
#include "task/forms/defaults/cui/screens/menu/main.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/structure/input/tasks.h"

MenuItem StructureMenu() {
    MenuItem structs;
    MenuItem s[3];

    s[0].SetCommand(new Label("menu_structure_list"), ListStart);
    s[1].SetCommand(new Label("menu_structure_queue"), QueueStart);
    s[2].SetCommand(new Label("menu_structure_stack"), StackStart);

    structs.SetItems(new Label("menu_structure"))->Vertical(true);
    for (i = 0; i < 3; i++) structs.Add(s[i]);

    return structs;
}
