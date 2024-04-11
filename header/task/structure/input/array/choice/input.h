#ifndef TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT
#define TASK_STRUCTURE_INPUT_ARRAY_CHOICE_INPUT

#include "task/structure/shared/array.h"
#include "task/structure/input/array/menu.h"
#include "task/structure/input/array/annotation/input.h"
#include "task/structure/input/array/annotation/value.h"

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
void InputChoice(SharedArray<TYPE>& array) {
    ArrayElements(limits);
    numeric->Bounds(limits);

    short input = InputOption();
    short size = array.original.size();

    void (*element[2])(std::vector<TYPE>&, char) = {
        ValueRandom, ValueManual
    };

    for (short i = 0; i < size; i++) {
        ArrayProgress(i, size);
        element[input](array.original, i);
    }
    ArrayProgress(size, size);
    array.Duplicate();
}

#endif
