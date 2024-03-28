#ifndef SCREEN_CONTROLS_MATRIX_PEN_FORMATTER
#define SCREEN_CONTROLS_MATRIX_PEN_FORMATTER

class Formatter {
    public:
        template<typename TYPE>
        Formatter* FText(const wchar_t* format, TYPE argument);

        template<typename TYPE>
        Formatter* Text(TYPE argument);

        template<typename T, typename... Args>
        void Text(T t, Args... args);
};

#endif
