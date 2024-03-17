#include "task/structure/input/menu/array.h"

#include <vector>
#include <string>

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/menuitem.h"
#include "screen/art/controls/menu/field/option.h"
#include "screen/art/controls/menu/field/label.h"
#include "task/structure/input/array/sorted.h"

Menu array_menu;

void ArrayMenu() {
    MenuItem array, exit;
    MenuItem result, sort, input, type;

    std::string caption = "menu_array_sort";
    result.SetCommand(new Label(caption), StartArraySort);
    sort.SetField(new Option(ArraySortParams()));
    input.SetField(new Option(ArrayInputParams()));
    type.SetField(new Option(ArrayTypeParams()));

    array.SetItems(new Label("menu_array"))->Vertical(true);
    array.Add(&result)->Add(&sort)->Add(&input)->Add(&type);

    exit.SetExit(new Label("menu_exit"));

    array_menu.SetItems()->Add(&array)->Add(&exit);
    array_menu.Index({ 0, 0 });
}

std::vector<std::string> ArraySortParams() {
    return {
        "menu_sort_array_insertions", "menu_sort_array_selection",
        "menu_sort_array_hoar", "menu_sort_array_hoar_no_recursion"
    };
}
std::vector<std::string> ArrayInputParams() {
    return {
        "menu_array_generation_random",
        "menu_array_generation_manual"
    };
}
std::vector<std::string> ArrayTypeParams() {
    return {
        "menu_array_type_numbers", "menu_array_type_strings"
    };
}
