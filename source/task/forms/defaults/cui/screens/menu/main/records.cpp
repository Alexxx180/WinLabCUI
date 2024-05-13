#include "task/forms/defaults/cui/screens/menu/main.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "screen/controls/menu/field/option.h"
#include "task/structure/input/tasks.h"

MenuItem[2] FilesMenu() {
    MenuItem file[2], text[2];

    text[0].SetCommand(new Label("menu_practice_file_text_word"), TextSearch);
    text[1].SetCommand(new Label("menu_practice_file_text_number"), SquareNumbers);

    file[0].SetItems(new Label("menu_practice_files_text"));
    for (i = 0; i < 2; i++) file[0].Add(text[i]);

    file[1].SetCommand(new Label("menu_practice_files_binary"), ShowBinary);
    return file;
}

MenuItem[2] RecordsMenu() {
    MenuItem week[2];

    week[0].SetField((new Option(RecordsWeek()))->Current(0));
    week[1].SetCommand(new Label("menu_practice_structure_filter"), ShowRecords);

    return week;
}

std::vector<std::string> RecordsWeek() {
    return {
        "menu_practice_records_week_monday",
        "menu_practice_records_week_tuesday",
        "menu_practice_records_week_wednesday",
        "menu_practice_records_week_thursday",
        "menu_practice_records_week_friday",
        "menu_practice_records_week_saturday",
        "menu_practice_records_week_sunday"
    };
}
