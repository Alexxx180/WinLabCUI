#include "screen/matrix/pen.h"

#include <cstdlib>

#include "common/texts/common.h"
#include "screen/drawing/types/layers.h"

void Pen :: Reset() { system(CLEAN_COMMAND); }

Pen* Pen :: Redraw() {
    Reset();
    std::vector<Grid>::iterator panel = Out.begin();
    while (panel != Out.end()) {
        panel->Show();
        panel++;
    }
    return this;
}

Pen* Pen :: Append(Grid panel, Booker layer) {
    Out.push_back(panel);
    Canvas.push_back(layer);
    return this;
}

Pen* Pen :: Target(short current) {
    screen = &Canvas[current];
    back = &Out[current];
    return this;
}

Pen* Pen :: Input(Typer* field) {
    do {
        Target(MAIN);
        screen->Decoration();
        field->TypeInput();
    }
    while (!field->IsVerified());
    return this;
}

Pen* Pen :: Clip(std::string name) {
    std::wcout << texts.at(name);
    return this;
}
