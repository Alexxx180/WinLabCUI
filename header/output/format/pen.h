#ifndef CLEAN_COMMAND
#define CLEAN_COMMAND "cls"

#include <windows.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "screen/art/drawing.h"
#include "screen/interaction.h"
#include "common/texts/common.h"
#include "output/booker.h"
#include "input/typer.h"
#include "screen/art/controls/grid.h"
#include "screen/art/controls/layers.h"
#include "screen/art/controls/bar.h"

class Pen {
private:
    Pen() { }
    std::vector<Grid> Out = {};
    std::vector<Booker> Canvas = {};
public:
    static Pen& ink() {
        static Pen instance;
        return instance;
    }

    Bar status;
    Booker* screen;
    Grid* back;

    void Reset() {
        system(CLEAN_COMMAND);
    }

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

    Pen* PrintSize() {
        wprintf(L"Canvas: %i", static_cast<int>(Canvas.size()));
        wprintf(L"; Out: %i", static_cast<int>(Out.size()));
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

    Pen* Clear() {
        screen->Clear();
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
