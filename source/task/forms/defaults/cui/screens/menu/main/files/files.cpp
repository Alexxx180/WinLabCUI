#include "task/forms/defaults/cui/screens/menu/main/files/files.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/forms/defaults/cui/screens/menu/main/files/text.h"
#include "task/structure/process/practice/files/binary.h"

MenuItem FilesMenu() {
    MenuItem files, f[2];
    f[0] = TextFilesMenu();
    f[1].SetCommand(new Label("menu_practice_file_binary"), Binary);

    files.SetItems(new Label("menu_practice_file"));
    for (char i = 0; i < 2; i++) files.Add(&f[i]);
    return files;
}
