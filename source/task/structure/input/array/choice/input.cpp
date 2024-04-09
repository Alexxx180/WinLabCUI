#include "task/structure/input/array/choice/input.h"

#include "task/forms/defaults/io/input.h"
#include "task/structure/shared/arrays.h"
#include "task/structure/input/array/menu.h"
#include "task/structure/input/array/annotation/input.h"

void InputDimension() {
    Boundary<char> length(1, 20);
    ArrayDimension(length);
    numeric->Bounds(length);
    numeric->Input();
    original.resize(numeric->result);
}

void InputChoice() {
    ArrayElements(limits);
    numeric->Bounds(limits);

    short input = InputOption();
    short size = original.size();

    input_type element[2] = { ValueRandom, ValueManual };

    for (short i = 0; i < size; i++) {
        ArrayProgress(i, size);
        char result = element[input]();
        original[i] = result;
    }
    ArrayProgress(size, size);

    sorted = original;
}
