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

void InputParameterName(std::wstring) {
    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(L" ", parameter);
}

template<typename TYPE>
void InputParameterValue(Verifier<TYPE>* limit) {
    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit);
}

void InputParameterFeedback(std::wstring) {
    Pen::ink().screen->Page(0)->Move()->Span(field);
    Pen::ink().screen->Clear()->Move()->Span(1);
    Pen::ink().Text(L" = ", parameter);
}

template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    InputParameterName(parameter);

    limit->Edges()->View();

    InputParameterFeedback(parameter);
    Pen::ink().Text(limit->result);
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

void ManualArrayInput() {
    InputParameterValue(numeric);
}

void RandomArrayInput() {
    Boundary<short>* limits = numberic->Edges();

    short size = limits->start + limits.end + 1;

    numeric->result = rand() % size + limits->start;
}

short (*array_input)(void);

std::vector<short> ArrayInputLoop() {
    std::vector<short> result(size);
    Boundary<short> limits(-99, 99);

    numeric->SetBounds(limits);

    InputParameterName(texts["input_array_elements"]);

    numeric->Edges->View();

    short i = 0;

    while (i < size) {
        array_input();
        result.push_back(numeric->result);

        Pen::ink().screen.Span(1)->Page(field + 1);
        Pen::ink().screen->Move()->Clear();
        Pen::ink().Text(size, L" / ", ++i);
    }

    return result;
}

void QueryArray() {
    original = ArrayInputLoop();
    sorted = original;

    Pen::ink().array.Show();
    Pen::ink().screen.Span(1)->Form(4)->Size(2);
    Pen::ink().Quote("output_source_array");
    Pen::ink().screen.Line();
    Pen::ink().Quote("output_sorted_array");

    while () {
        Pen::ink().screen.Line(-1);
        Pen::ink().Quote("input_results");
        Pen::ink().Text(pages.Y, L" / ", pages.X);
        Pen::ink().screen.Page(1)->Line(0);
        while (max_size) {
            Pen::ink().screen.Line(0);
            Pen::ink().FText(L"%4i", original[i]);
            Pen::ink().screen.Line(1);
            Pen::ink().FText(L"%4i", sorted[i]);
        }
    }
}

std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP
};

void SelectOption() {
    switch (current_menu_option) {
        case -1:
            QueryArray();
            break;
        default:

            break;
    }
}

void ArrayMenuLoop() {
    char code = Select(menu_input_keys);
    NavigateMenuOption(code == KEY_UP ? -1 : 1);


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

