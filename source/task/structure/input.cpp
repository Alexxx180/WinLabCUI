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

void SetStatusSignal() {
    Pen* (Pen::*signal)(std::string) = NULL;

    signal = static_cast<Pen* (Pen::*)(std::string)>(&Pen::Quote);

    numeric->status.Server(FOOT)->Signal(signal);
}

void InputHeader() {
    Pen::ink().Redraw()
    Pen::ink().Target(FOOT)->Quote("status_forward");
    SetStatusSignal();
    Pen::ink().Target(MAIN);
    Pen::ink().screen->Form(0)->Page(0)->Span(4)->Size(2)->Line(0);
    Pen::ink().Quote("input_header")->screen->Span(1);
}

void Input() {
    field = 4;

    InputHeader();

    Boundary<short> precision(1, 20);
    numeric->Bounds(&precision);

    Await(ArrayMenuLoop);
}

