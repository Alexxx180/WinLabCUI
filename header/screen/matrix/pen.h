#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include <iostream>
#include <vector>

#include <cstdlib>

#include "common/texts/common.h"
#include "input/typer.h"
#include "screen/art/drawing.h"
#include "screen/art/layers.h"
#include "screen/art/controls/grid.h"
#include "screen/art/controls/bar.h"
#include "screen/matrix/booker.h"

class Pen {
private:
    Pen() { SetSignals(); }

    std::vector<Grid> Out = {};
    std::vector<Booker> Canvas = {};

    Pen* (Pen::*m_write)(std::string);

    void SetSignals() {
        m_write = Quote;
        //m_write = static_cast<Pen* (Pen::*)(std::string)>(&Quote);
    }

public:
    static Pen& ink() {
        static Pen instance;
        return instance;
    }

    Bar status;
    Booker* screen;
    Grid* back;
    Grid array;

    void Reset() { system(CLEAN_COMMAND); }

    Pen* (Pen::*)(std::string) Feedback() { return m_write; }

    Pen* Redraw() {
        Reset();
        std::vector<Grid>::iterator panel = Out.begin();
        while (panel != Out.end()) {
            panel->Show();
            panel++;
        }
        return this;
    }

    Pen* Append(Grid panel, Booker layer) {
        Out.push_back(panel);
        Canvas.push_back(layer);
        return this;
    }

    Pen* Target(short current) {
        screen = &Canvas[current];
        back = &Out[current];
        return this;
    }

    Pen* Input(Typer* field) {
        do {
            Target(MAIN);
            screen->Decoration();
            field->TypeInput();
        }
        while (!field->IsVerified());
        return this;
    }

    Pen* Quote(std::string name) {
        screen->Clear()->Move();
        std::wcout << texts[name];
        return this;
    }

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

    // Note: method will output arguments in reverse order
    template<typename T, typename... Args>
    void Text(T t, Args... args) {
        Text(args...);
        std::wcout << t;
    }
};

#endif
