#include "task/forms/defaults/cui/screens/menu/main/practice.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/forms/defaults/cui/screens/menu/main/records.h"
#include "task/structure/input/tasks.h"
#include "task/structure/process/practice/strings.h"

MenuItem PracticeMenu() {
    MenuItem practice, p[3];
    MenuItem w[2] = RecordsMenu();
    MenuItem f[2] = FilesMenu();
    char i;

    p[0].SetCommand(new Label("menu_practice_strings"), ShowStrings);

    p[1].SetItems(new Label("menu_practice_structure"));
    for (i = 0; i < 2; i++) p[1].Add(w[i]);

    p[2].SetItems(new Label("menu_practice_file"));
    for (i = 0; i < 2; i++) p[2].Add(f[i]);

    practice.SetItems(new Label("menu_practice"))->Vertical(true);
    for (i = 0; i < 4; i++) practice.Add(p[i]);

    return practice;
}
