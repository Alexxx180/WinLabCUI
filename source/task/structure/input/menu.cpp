#include "task/structure/input/array/menu.h"

#include "task/forms/defaults/cui/screens/menu/week.h"
#include "screen/controls/menu/menuitem.h"

MenuItem& RecordOptions() {
    return main_menu.Get().at(1).at(1);
}

char WeekOption() {
    return RecordOptions().at(1).Choice();
}
