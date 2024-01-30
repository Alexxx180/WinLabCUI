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

short field;

Verifier<float>* floating = new Verifier<float>();
Verifier<short>* numeric = new Verifier<short>();

void SetStatusSignal() {
    Pen* (Pen::*signal)(std::string) = NULL;

    signal = static_cast<Pen* (Pen::*)(std::string)>(&Pen::Quote);

    Pen::ink().Redraw()->Target(FOOT)->Quote("status_forward");

    floating->status.Server(FOOT)->Signal(signal);
    numeric->status.Server(FOOT)->Signal(signal);
}

template<typename TYPE>
void InputParameter(Verifier<TYPE>* limit, std::string name) {
    std::wstring parameter = texts[name];

    Pen::ink().screen->Line();
    Pen::ink().Text(L" ", parameter);

    limit->Edges()->View();

    Pen::ink().screen->Page(field);
    Pen::ink().Input(limit)->screen->Page(0);

    Pen::ink().screen->Clear()->Move();
    Pen::ink().Text(limit->result, L" = ", parameter);
}

Period Input() {
    Period result;
    field = 4;

    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(field - 1)->Span(4)->Size(2)->Line(0);

    Pen::ink().Quote("input_header")->screen->Line()->Span(1);

    Boundary<short> precision(0, 10);
    Boundary<float> value(-10.0f, 1.0f);

    numeric->Bounds(&precision);
    floating->Bounds(&value);

    InputParameter(numeric, "input_x_recursion");
    result.precision.X = numeric->result;

    Pen::ink().screen->Line();
    Pen::ink().Quote("input_f_algorithms");

    InputParameter(floating, "input_f_argument");
    result.x = floating->result;

    InputParameter(numeric, "input_f_precision");
    result.precision.Y = numeric->result;

    return result;
}

