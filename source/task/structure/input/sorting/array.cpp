#include "task/structure/input.h"

#include <vector>
#include <string>
#include <cstdlib>

#include "common/texts/common.h"
#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "task/structure/input/common/data.h"
#include "task/structure/input/sorting/parameters.h"
#include "task/structure/markdown/debug.h"
#include "task/structure/menu/array.h"
#include "task/structure/output/sort.h"
#include "task/forms/debug.h"
#include "screen/matrix/pen.h"

void ManualArrayInput() { InputParameterValue(numeric); }

void (*array_input)(void)[2] = {
    randomc.Standard, ManualArrayInput
};

std::vector<short> ArrayInputLoop(short size) {
    std::vector<short> result(size);

    numeric->SetBounds(&randomc.limits);

    InputParameterName(texts["input_array_elements"]);

    numeric->Edges->View();

    short i = 0;
    short option = array_menu[0][2].values.SelectedIndex();

    input_array = array_input[option];

    while (i < size) {
        input_array();
        result.push_back(numeric->result);

        Pen::ink().screen->Span(1)->Page(3);
        Pen::ink().screen->Move()->Clear();
        Pen::ink().Text(size, L" / ", ++i);
    }

    return result;
}

void (*array_sort)(std::vector<short>&)[4] = {
    HoarRecursive, QuickSortIterative,
    InsertionsSort, SelectionSort
};

void QueryArray() {
    Boundary<short> limits(1, 20);
    numeric->Bounds(&limits);

    short size = numeric->result;

    original = ArrayInputLoop(size);
    short option = array_menu[0][1].values.SelectedIndex();

    sorted = array_sort[option](original);

    Pen::ink().array.Show();
    Pen::ink().screen.Span(1)->Form(1)->Size(2);
    Pen::ink().Quote("output_source_array");

    Pen::ink().screen.Line();
    Pen::ink().Quote("output_sorted_array");
    OutputArraySort();
}

void InputHeader() {
    Pen::ink().Target(FOOT)->Quote("status_forward");
    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(0)->Span(4)->Size(2)->Line(0);
    Pen::ink().Quote("input_header")->screen->Span(1);
}

void StartArraySort() {
    InputHeader();

    Boundary<short> precision(1, 20);
    numeric->Bounds(&precision);
}
