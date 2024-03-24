#include "task/structure/input/array/original.h"

#include <vector>
#include <string>
#include <cstdlib>

#include "common/types.h"
#include "common/texts/common.h"
#include "screen/matrix/pen.h"
#include "task/structure/input/common/data.h"
#include "task/structure/input/common/parameters.h"
#include "task/structure/input/array/common.h"
#include "task/forms/debug.h"

void ManualInput() { InputParameterValue(numeric); }
void RandomInput() { randomc.Standard(); }

typedef void (*invokation)();

invokation DetermineInput() {
    void (*array_input[2])(void) = { RandomInput, ManualInput };
    byte option = ArrayOptions().at(2).Choice();

    return array_input[option];
}

void (*array_input[2])(void) = {
    RandomArrayInput, ManualArrayInput
};

std::vector<short> ArrayInputLoop(short size) {
    std::vector<short> result(size);
    std::wstring name = texts["input_array_elements"];

    numeric->Bounds(&randomc.limits);
    InputParameterName(name);
    numeric->Edges()->View();

    byte i = 0, perform_input = DetermineInput();

    while (i < size) {
        perform_input();
        result.push_back(numeric->result);

        out->Span(1)->Page(3)->Move()->Clear();
        pen->Text(++i, L" / ", size);
    }

    return result;
}
