#include "task/structure/input/menu/array.h"

#include <vector>
#include <string>

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/option.h"
#include "task/structure/input/array/sorted.h"

Menu array_menu;

void ArrayMenu() {
    MenuItem result, sort, input, type;

    std::vector<std::vector<std::string>> options = ArrayMenuOptions();

    result.SetCaption("menu_array_sort");
    result.SetCommand(StartArraySort);

    sort.SetValues((new Option())->Values(options[0])->Current(0));
    input.SetValues((new Option())->Values(options[1])->Current(0));
    type.SetValues((new Option())->Values(options[2])->Current(0));

    MenuItem array, exit;

    array.SetCaption("menu_tasks");
    array.SetItems()->SetDirection(false);
    array.Add(&result)->Add(&sort)->Add(&input)->Add(&type);

    exit.SetCaption("menu_exit")->SetExit();

    array_menu.SetItems()->SetDirection(true);
    array_menu.Add(&array)->Add(&exit);
}

std::vector<std::vector<std::string>> ArrayMenuOptions() {
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
