#include "screen/controls/matrix/pen/formatter.h"

#include <iostream>

template<typename TYPE>
Formatter* Formatter :: FText(const wchar_t* format, TYPE argument) {
    wprintf(format, argument);
    return this;
}

template<typename TYPE>
Formatter* Formatter :: Text(TYPE argument) {
    std::wcout << argument;
    return this;
}

template<typename T, typename... Args>
void Formatter :: Text(T current, Args... args) {
    std::wcout << current;
    Texts(args...);
}
