#include "task/structure/input/menu/array.h"

#include <vector>
#include <string>

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/content/option.h"
#include "screen/art/controls/menu/content/label.h"
#include "screen/matrix/types/point.h"
#include "task/structure/input/array/sorted.h"

Menu array_menu;

void ArrayMenu() {
	Point position = { 0, 0 };
    MenuItem result, sort, input, type;

    std::vector<std::vector<std::string>> options = ArrayMenuOptions();

    result.SetCaption(std::move(new Label("menu_array_sort")));
    result.SetCommand(StartArraySort);

    sort.SetValues(std::move((new Option())->Values(options[0])));
    input.SetValues(std::move((new Option())->Values(options[1])));
    type.SetValues(std::move((new Option())->Values(options[2])));

    MenuItem array, exit;

    array.SetCaption(std::move(new Label("menu_array")));
    array.SetItems()->SetDirection(true);
    array.Add(&result)->Add(&sort)->Add(&input)->Add(&type);

    exit.SetCaption(std::move(new Label("menu_exit")))->SetExit();

    array_menu.SetItems()->SetDirection(false);
    array_menu.Add(&array)->Add(&exit)->Index(position);
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
