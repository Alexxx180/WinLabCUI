#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT

#include "task/forms/defaults/io/input.h"
#include "task/structure/input/array/menu.h"
#include "task/structure/input/array/annotation/input.h"

template<typename TYPE>
void InputDimension(std::vector<TYPE>& original) {
    Boundary<char> length(1, 20);
    ArrayDimension(length);
    numeric->Bounds(length);
    numeric->Input();
    original.resize(numeric->result);
    ClearDimension();
}

template<typename TYPE>
void InputChoice(std::vector<TYPE>& original) {
    ArrayElements(limits);
    numeric->Bounds(limits);

    short input = InputOption();
    short size = original.size();

    void (*element)(std::vector<TYPE>&, char)[2] = {
        ValueRandom, ValueManual
    };

    for (short i = 0; i < size; i++) {
        ArrayProgress(i, size);
        element[input](original, i);
    }
    ArrayProgress(size, size);

    sorted = original;
}

#endif
