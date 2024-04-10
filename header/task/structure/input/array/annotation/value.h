#include <vector>

#include "task/forms/defaults/io/input.h"
#include "screen/interaction/interaction.h"

template<typename TYPE>
void ValueManual(std::vector<TYPE>& original, char i) {}

template <>
void ValueManual(std::vector<short>& original, char i) {
    numeric->Input();
    original[i] = numeric->result;
}

template <>
void ValueManual(std::vector<std::wstring>& original, char i) {
    prompts->Input();
    original[i] = prompts->result;
}


template<typename TYPE>
void ValueRandom(std::vector<TYPE>& original, char i) {}

template <>
void ValueRandom(std::vector<short>& original, char i) {
    original[i] = gen_int8.Random();
}

template <>
void ValueRandom(std::vector<std::wstring>& original, char i) {
    Boundary<char> latin(97, 25);
    char symbol;

    original[i] = L"";
    for (char c = 0; c < 3; c++) {
        symbol = rand() % latin.end + latin.start;
        original[i].push_back(symbol);
    }
}
