#include "task/structure/input/common/data.h"

#include "task/forms/defaults/io/input.h"

void FillArray(char size, char* array) {
    while (--size >= 0) array[size] = gen_int8.Random();
}

void FillArrays(char count, char size, char** arrays) {
    while (--count >= 0) FillArray(size, arrays[count]);
}

void EmptyArray(char size, short* array) {
    while (--size >= 0) array[size] = 0;
}
