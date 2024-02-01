#include "task/structure/input.h"

#include <math.h>
#include <string>

#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

short field;

Verifier<short>* numeric = new Verifier<short>();

void SetStatusSignal() {
    Pen* (Pen::*signal)(std::string) = NULL;

    signal = static_cast<Pen* (Pen::*)(std::string)>(&Pen::Quote);

    Pen::ink().Redraw()->Target(FOOT)->Quote("status_forward");

    numeric->status.Server(FOOT)->Signal(signal);
}

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

Boundary<short> main_menu(0, 1), array_menu(-1, menu_options.size() - 1);

void NavigateMenuOption(Boundary<short> menu, short direction) {
    short next = current_menu_option + direction;
    if (menu.Verify(next))
        current_menu_option = next;
}

std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

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

bool SelectMenuOption() {
    bool is_exit = false;

    switch (current_menu_option) {
        case 0:
            current_menu_option = -1;
            Await(ArrayMenuLoop(), ESC);
            break;
        case 1:
            is_exit = Select(ESC, ENTER) == ENTER;
            break;
        default:
            array_options[current_menu_option].Next();
            break;
    }

    return is_exit;
}

bool MenuLoop() {
    char code = Select(menu_input_keys);
    bool is_exit = false;

    switch (code) {
        case ENTER: is_exit = SelectMenuOption(); break;
        case KEY_LEFT:
            NavigateMenuOption(main_menu, -1);
            break;
        case KEY_RIGHT:
            NavigateMenuOption(main_menu, 1);
            break;
        default: break;
    };

    return is_exit;
}

void InputHeader() {
    SetStatusSignal();
    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(0)->Span(4)->Size(2)->Line(0);
    Pen::ink().Quote("input_header")->screen->Span(1);
}

void Input() {
    field = 4;

    InputHeader();

    Boundary<short> precision(1, 20);
    numeric->Bounds(&precision);

    Await(ArrayMenuLoop);
}

