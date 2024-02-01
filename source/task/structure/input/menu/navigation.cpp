#include "input/boundary.h"
#include "screen/interaction.h"

void NavigateMenuOption(Boundary<short> menu, short direction) {
    short next = current_menu_option + direction;
    if (menu.Verify(next))
        current_menu_option = next;
}

std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

std::vector<std::vector<std::string>> menu_options = {
    {
        "menu_sort_array_insertions",
        "menu_sort_array_selection",
        "menu_sort_array_hoar",
        "menu_sort_array_hoar_no_recursion"
    },
    {
        "menu_array_generation_random",
        "menu_array_generation_manual"
    },
    {
        "menu_array_type_numbers",
        "menu_array_type_strings"
    },
};

Boundary<short> main_menu(0, 1);
Boundary<short> array_menu(-1, menu_options.size() - 1);
