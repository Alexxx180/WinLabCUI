#include "task/structure/input/menu.h"
#include "task/forms/defaults/cui/screens/menu/main.h"

MenuItem& RecordOptions() {
    return main_menu.Get().at(1).at(1);
}

char WeekOption() {
    return RecordOptions().at(0).Choice();
}
