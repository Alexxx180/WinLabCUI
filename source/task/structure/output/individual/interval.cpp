#include "task/structure/output/individual/interval.h"

#include "screen/matrix/tools.h"
#include "task/forms/defaults/io/input.h"

void ElementsInterval(char N) {
    char D2 = gen_int8.limits.end;
    pen->Clip("individual_source_data");
    pen->Text(": N = ", N, ", D1 = 0, D2 = ")->FText(L"%i", D2);
    out->Line();
}

void ElementsSum(std::wstring name, short max) {
    out->Line()->Move();
    pen->Clip("individual_arrays_name")->Text(L": ", name, L", ");
    pen->Clip("individual_arrays_sum")->Text(": ", max);
}
