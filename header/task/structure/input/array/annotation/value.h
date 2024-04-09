#include <vector>

#include "task/forms/defaults/io/input.h"

template <typename TYPE>
void ValueManual(std::vector<TYPE>& original, char i) {}

template<typename TYPE>
void ValueManual(std::vector<short>& original, char i) {
    original[i] = numeric->Input();
}

template<typename TYPE>
void ValueManual(std::vector<std::string>& original, char i) {
    original[i] = prompts->Input();
}


template<typename TYPE>
void ValueRandom(std::vector<TYPE>& original, char i) {}

template<typename TYPE>
void ValueRandom(std::vector<short>& original, char i) {
    original[i] = gen_int8.Random();
}

template<typename TYPE>
void ValueRandom(std::vector<std::string>& original, char i) {
    original[i].push_back(gen_int8.Random());
}
