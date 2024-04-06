#ifndef SCREEN_CONTROLS_MATRIX_PEN_FORMATTER
#define SCREEN_CONTROLS_MATRIX_PEN_FORMATTER

#include <iostream>
#include <string>

class Formatter {
    private:
        template <typename T>
        void Print(const T t) {
            std::wcout << t;
        }

        void Print(std::string t) {
            std::cout << t;
        }

    public:
        template<typename TYPE>
        Formatter* FText(const wchar_t* format, TYPE argument) {
            wprintf(format, argument);
            return this;
        }

        Formatter* Text() { return this; }

        template <typename T, typename...args>
        Formatter* Text(T first, args... rest) {
            Print(first);
            return Text(rest...);
        }
};

#endif
