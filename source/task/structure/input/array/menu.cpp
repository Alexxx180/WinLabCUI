#include "task/structure/input/array/menu.h"

#include "task/forms/defaults/cui/screens/menu/array.h"
#include "screen/controls/menu/menuitem.h"

MenuItem& ArrayOptions() {
    return array_menu.Get().at(0);
}

char SortOption() {
    return ArrayOptions().at(1).Choice();
}

char InputOption() {
    return ArrayOptions().at(2).Choice();
}
