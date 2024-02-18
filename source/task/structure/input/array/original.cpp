#include "task/structure/input/array/original.h"

#include <vector>
#include <string>
#include <cstdlib>

#include "common/texts/common.h"
#include "task/structure/input/common/data.h"
#include "task/structure/input/menu/array.h"
#include "task/structure/markdown/debug.h"
#include "task/structure/menu/array.h"
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

    short i = 0, option = array_menu[0][2].values.SelectedIndex();

    input_array = array_input[option];

    while (i < size) {
        input_array();
        result.push_back(numeric->result);

        Pen::ink().screen->Span(1)->Page(3);
        Pen::ink().screen->Move()->Clear();
        Pen::ink().Text(++i)->Text(L" / ")->Text(size);
    }

    return result;
}
