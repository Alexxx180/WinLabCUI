#include "task/structure/input/array/original.h"

#include "common/types.h"
#include "screen/matrix/tools.h"

#include "task/forms/defaults/io/input.h"

#include "task/structure/input/common/data.h"
#include "task/structure/input/common/parameters.h"
#include "task/structure/input/array/common.h"

void ManualInput() { ValueInput(numeric); }
void RandomInput() { random_char.Random(); }

invokation InputSelect() {
    invokation array_input[2] = { RandomInput, ManualInput };
    return array_input[InputOption()];
}

std::vector<short> ArrayInput(short size) {
    std::vector<short> result(size);
    Boundary<char>* limits = &gen_int8.limits;

    numeric->Bounds(limits);
    NameInput("input_array_elements");
    pen->Bounds(limits);

    byte i = 0, perform_input = InputSelect();

    while (i < size) {
        perform_input();
        result.push_back(numeric->result);

        out->Span(1)->Page(3)->Move()->Clear();
        pen->Text(++i, L" / ", size);
    }

    return result;
}
