#include "task/structure/output/individual/interval.h"

#include "common/texts/format.h"
#include "screen/matrix/tools.h"
#include "task/forms/defaults/io/input.h"

void ElementsInterval(char N) {
    char D2 = limits.end;
    out->Move();
    out->Clip("individual_source_data");
    out->Text(L": N = ")->FText(NO, N);
    out->Text(L", D1 = 0, D2 = ");
    out->FText(NO, D2)->Line();
}

void ElementsSum(std::wstring name, short max) {
    out->Line()->Move();
    out->Clip("individual_arrays_name");
    out->Text(L": ", name, L", ");
    out->Clip("individual_arrays_sum");
    out->Text(L": ", max);
}
