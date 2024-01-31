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

Verifier<float>* floating = new Verifier<float>();
Verifier<short>* numeric = new Verifier<short>();

void SetStatusSignal() {
    Pen* (Pen::*signal)(std::string) = NULL;

    signal = static_cast<Pen* (Pen::*)(std::string)>(&Pen::Quote);

    Pen::ink().Redraw()->Target(FOOT)->Quote("status_forward");

    floating->status.Server(FOOT)->Signal(signal);
    numeric->status.Server(FOOT)->Signal(signal);
}

template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(L" ", parameter);

    limit->Edges()->View();

    Pen::ink().screen->Span(field)->Clear()->Move()->Span(1)->Move();
    Pen::ink().Text(limit->result, L" = ", parameter);
}

template<typename TYPE>
void InputParameterValue(Verifier<TYPE>* limit) {
    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit);
}

void InputParameterFeedback(std::wstring) {
    Pen::ink().screen->Page(0)->Move()->Span(field);
    Pen::ink().screen->Clear()->Move()->Span(1);
    Pen::ink().Text(parameter);
}

template<typename TYPE>
void InputArrayParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    limit->Edges()->View();

    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit)


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

void NavigateMenuOption(short direction) {
    short next = current_menu_option + direction;
    if (array_menu.Verify(next))
        current_menu_option = next;
}

std::vector<short> ArrayInputLoop(short size) {
    std::vector<short> result(size);
    Boundary<short> limits(-99, 99);

    numeric->SetBounds(limits);

    std::wstring parameter = texts["input_array_elements"];

    for (short i = 0; i < size; i++) {
        Pen::ink().screen->Line()->Move();
        Pen::ink().Text(L" ", parameter);

        numeric->Edges()->View();

        InputArrayParameter(numeric, "input_f_precision");
        result.push_back(numeric->result);
    }

    return ;
}

std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP
};

void {
    switch () {
        case -1:
            break;
        default:
            break;
    }
}

void ArrayMenuLoop() {
    char code = Select(menu_input_keys);
    Navigate
    if (code) {

    }

    switch () {

    }

    
}

void Input() {
    field = 4;

    SetStatusSignal();
    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(0)->Span(4)->Size(2)->Line(0);

    Pen::ink().Quote("input_header")->screen->Span(1);

    Boundary<short> precision(1, 20);
    numeric->Bounds(&precision);



}

