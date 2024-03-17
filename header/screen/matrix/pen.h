#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include <iostream>
#include <vector>

#include "input/typer.h"
#include "screen/art/drawing.h"
#include "screen/art/types/layers.h"
#include "screen/art/controls/grid.h"
#include "screen/art/controls/bar.h"
#include "screen/matrix/booker.h"

class Pen {
private:
    std::vector<Grid> Out;
    std::vector<Booker> Canvas;

protected:
    Pen() { }

public:
    typedef Pen* (Pen::*quoteptr)(std::string);

    quoteptr Feedback();
    static const Pen& ink();

    Bar status;
    Booker* screen;
    Grid* back;
    Grid array;

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
