#include "task/structure/input/array/choice/input.h"

#include "common/types.h"
#include "screen/matrix/tools.h"

#include "task/forms/defaults/io/input.h"

#include "task/structure/input/common/data.h"
#include "task/structure/input/common/parameters.h"
#include "task/structure/input/array/common.h"

void ManualInput() { ValueInput(numeric); }
void RandomInput() { gen_int8.Random(); }

invokation InputSelect() {
    invokation array_input[2] = { RandomInput, ManualInput };
    return array_input[InputOption()];
}

std::vector<short> ArrayInput(short size) {
    std::vector<short> result(size);

    numeric->Bounds(&gen_int8.limits);
    NameInput("input_array_elements");
    out->Bounds(gen_int8.limits);

    byte i = 0;
    invokation perform_input = InputSelect();

    while (i < size) {
        perform_input();
        result.push_back(numeric->result);

        out->Span(1)->Page(3);
        out->Move()->Clear()->Move();
        out->Text(++i, L" / ", size);
    }

    return result;
}
