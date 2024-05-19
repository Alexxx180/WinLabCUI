#include "task/forms/defaults/cui/screens/menu/main/practice.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/forms/defaults/cui/screens/menu/main/records.h"
#include "task/forms/defaults/cui/screens/menu/main/files/files.h"
#include "task/structure/process/practice/strings.h"

MenuItem PracticeMenu() {
    MenuItem practice, p[3];
    p[0].SetCommand(new Label("menu_practice_string"), ShowStrings);
    p[1] = RecordsMenu();
    p[2] = FilesMenu();

    practice.SetItems(new Label("menu_practice"))->Vertical(true);
    for (char i = 0; i < 3; i++) practice.Add(&p[i]);
    return practice;
}
