#include "task/forms/defaults/cui/screens/menu/main/records.h"

#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/label.h"
#include "screen/controls/menu/field/option.h"
#include "task/structure/process/practice/records/records.h"

MenuItem RecordsMenu() {
    MenuItem records, week[2];

    week[0].SetField((new Option(RecordsWeek()))->Current(0));
    week[1].SetCommand(new Label("menu_practice_structure_filter"), ShowRecords);

    records.SetItems(new Label("menu_practice_file"));
    for (char i = 0; i < 2; i++) records.Add(&week[i]);
    return records;
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
