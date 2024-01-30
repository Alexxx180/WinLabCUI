#include "task/structure/input.h"

#include <math.h>
#include <string>

#include "input/boundary.h"
#include "input/feedback/verifier.h"
#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"

Verifier<float>* floating = new Verifier<float>();
Verifier<short>* numeric = new Verifier<short>();

short field;

template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    Pen::ink().screen->Line();
    Pen::ink().Text(L" ", parameter);

    limit->Edges()->View();

    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit)->screen->Page(field - 1);

    Pen::ink().screen->Clear()->Move();
    Pen::ink().Text(limit->result, L" = ", parameter);
}

Loop InputLoop(const Boundary<float> *const initial, std::string name[3]) {
    Loop lap;
    float limit;
    Boundary<float> current(0.1f, initial->end);

    InputFloat(&current, name[0]);

    limit = floating->result;
    lap.step = limit * 10;
    current.start = initial->start;

    InputFloat(&current, name[1]);

    limit = floating->result;
    lap.start = limit * 10;
    current.start = limit;

    InputFloat(&current, name[2]);
    lap.end = floating->result * 10;

    return lap;
}

Loop2 Input() {
    Loop2 result;

    Pen* (Pen::*signal)(std::string) = NULL;

    signal = static_cast<Pen* (Pen::*)(std::string)>(&Pen::Quote);

    Pen::ink().Redraw()->Target(FOOT)->Quote("status_forward");

    floating->status.Server(FOOT)->Signal(signal);

    field = 4;

    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(field - 1)->Span(4)->Size(2)->Line(0);

    Pen::ink().Quote("input_header")->screen->Line()->Span(1);

    const Boundary<short> precision(0, 10);

    numeric->Bounds(precision);

    std::wstring parameter = "input_x_recursion";

    Pen::ink().Quote(parameter)->Text(L" ");
    numeric->Edges()->View();
    Pen::ink().screen->Page(field);
    Pen::ink().Input(numeric)->screen->Page(field - 1);

    Pen::ink().screen->Clear()->Move();
    Pen::ink().Text(numeric->result, L" = ", parameter);

    const Boundary<float> value(-10.0f, 1.0f);

    result.X = InputLoop(&bounds, name);

    field += 3;
    Pen::ink().screen->Page(field - 1)->Line(1);

    result.Y = InputLoop(&bounds, name);
    return result;
}
