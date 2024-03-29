#include "task/structure/input/common/data.h"

#include "task/forms/defaults/io/input.h"

template<typename TYPE>
void FillArray(TYPE size, TYPE* array) {
    while (--size >= 0) array[size] = gen_int8.Random();
}

template<typename TYPE>
void FillArrays(TYPE count, TYPE size, TYPE** arrays) {
    while (--count >= 0) FillArray(size, arrays[count]);
}

template<typename TYPE>
void EmptyArray(TYPE size, TYPE* array) {
    while (--size >= 0) array[size] = 0;
}
