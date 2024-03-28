#include "task/structure/input/menu/array.h"

#include <vector>
#include <string>

#include "screen/controls/menu/loop/exit.h"
#include "screen/controls/menu/menu.h"
#include "screen/controls/menu/menuitem.h"
#include "screen/controls/menu/field/option.h"
#include "screen/controls/menu/field/label.h"
#include "task/structure/input/array/sorted.h"

ExitMenu array_menu;

void ArrayMenu() {
    Menu context;
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

    context.SetItems()->Add(&array)->Add(&exit);
    context.Index({ 0, 0 });

    array_menu.Set(&context);
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
