#include "task/structure/input/array/annotation/input.h"

#include "task/forms/defaults/io/input.h"
#include "common/texts/format.h"
#include "screen/matrix/tools.h"

void ArrayDimension(Boundary<char>& length) {
    out->Line()->Move();
    out->Clip("input_array_dimension");
    out->Text(L" ")->FBounds(NO, length);
    out->Page(1)->Span(1);
}

void ClearDimension() {
    out->Jump()->Move()->Clear()->Line()->Move();
}

void ArrayElements(Boundary<char>& limits) {
    out->Page(0)->Line()->Move();
    out->Clip("input_array_elements");
    out->Text(L" ")->FBounds(NO, limits);
    out->Page(1)->Span(1)->Field();
}

void ArrayProgress(short at, short size) {
    out->Clear()->Move();
    out->Page(3)->Move();
    out->Clear()->Move();
    out->Text(at, L" / ", size);
    out->Page(1)->Move();
    out->Clear()->Move();
}

char ValueManual() {
    numeric->Input();
    return numeric->result;
}

char ValueRandom() {
    char value = gen_int8.Random();
    out->FText(NO, value);
    return value;
}
