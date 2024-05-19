#include "task/forms/defaults/cui/screens/menu/main/files/text.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "task/structure/process/practice/files/text/search.h"
#include "task/structure/process/practice/files/text/squares.h"

MenuItem TextFilesMenu() {
    MenuItem file, text[2];

    text[0].SetCommand(new Label("menu_practice_file_text_word"), TextSearch);
    text[1].SetCommand(new Label("menu_practice_file_text_number"), SquareEnum);

    file.SetItems(new Label("menu_practice_file_text"));
    for (char i = 0; i < 2; i++) file.Add(&text[i]);
    return file;
}
