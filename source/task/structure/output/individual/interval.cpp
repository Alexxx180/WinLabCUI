#include "task/structure/output/individual/interval.h"

#include "common/nameof.h"
#include "screen/matrix/tools.h"
#include "task/forms/defaults/io/input.h"

void ElementsInterval(char N) {
    char D2 = gen_int8.limits.end;
    out->Move();
    out->Clip("individual_source_data");
    out->Text(L": N = ", N, L", D1 = 0, D2 = ");
    out->FText(L"%i", D2);
    out->Line();
}

void ElementsSum(char* array, short max) {
    std::string name = NAMEOF(array);
    out->Line()->Move();
    out->Clip("individual_arrays_name");
    out->Text(L": ", name, L", ");
    out->Clip("individual_arrays_sum");
    out->Text(L": ", max);
}
