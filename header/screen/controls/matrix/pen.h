#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include <iostream>
#include <vector>

#include "input/feedback/typer.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/types/layers.h"
#include "screen/controls/layout/grid/grid.h"
#include "screen/controls/bar/bar.h"
#include "screen/matrix/booker.h"

class Pen {
    protected:
        Pen() {}

    public:
        static Pen& ink() {
            static Pen instance;
            return instance;
        }

        typedef Pen* (Pen::*quoteptr)(std::string);

        quoteptr Feedback() { return &Pen::Quote; }

        void Reset();
        Pen* Redraw();
        Pen* Append(Grid panel, Booker layer);
        Pen* Target(short current);
        Pen* Input(Typer* field);
        Pen* Quote(std::string name);

        template<typename TYPE>
        Pen* FText(const wchar_t* format, TYPE argument) {
            wprintf(format, argument);
            return this;
        }

        template<typename TYPE>
        Pen* Text(TYPE argument) {
            std::wcout << argument;
            return this;
        }

        template<typename T, typename... Args>
        void Texts(T t, Args... args) {
            std::wcout << t;
            Texts(args...);
        }
};

#endif
