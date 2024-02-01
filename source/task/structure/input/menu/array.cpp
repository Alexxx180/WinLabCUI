#include "task/structure/input/menu/array.h"

#include "screen/interaction.h"
#include "task/structure/markdown/debug.h"
#include "task/structure/input/array.h"
#include "task/structure/input/menu/navigation.h"

void SelectArrayOption() {
    switch (current_menu_option) {
        case -1: QueryArray(); break;
        default:
            array_options[current_menu_option].Next();
            break;
    }
}

char ArrayMenuLoop() {
    char code = Select(menu_input_keys);

    switch (code) {
        case ENTER: SelectArrayOption(); break;
        case KEY_UP: NavigateMenuOption(array_menu, -1); break;
        case KEY_DOWN: NavigateMenuOption(array_menu, 1); break;
        case KEY_LEFT:
            array_options[current_menu_option].Prev();
            break;
        case KEY_RIGHT:
            array_options[current_menu_option].Next();
            break;
        default: break;
    };

    return code;
}
