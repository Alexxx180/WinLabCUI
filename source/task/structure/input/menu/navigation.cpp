#include "input/boundary.h"
#include "screen/interaction.h"

void NavigateMenuOption(Boundary<short> menu, short direction) {
    short next = current_menu_option + direction;
    if (menu.Verify(next))
        current_menu_option = next;
}

std::vector<std::vector<string>> GetMenuOptions() {
    return {
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
}
