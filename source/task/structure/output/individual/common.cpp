#include "task/structure/output/individual/common.h"

#include "common/texts/format.h"
#include "screen/matrix/tools.h"

void ArrayOutput(std::wstring name, char size, char* array) {
    char first = array[0];
    out->Line()->Move();
    out->Text(name, L" = ");
    out->FText(NO4, first);

    for (char i = 1; i < size; i++)
        out->Text(L", ")->FText(NO4, array[i]);
}

void ArraysOutput(std::wstring* names, char count, char size, char** arrays) {
    for (char i = 0; i < count; i++)
        ArrayOutput(names[i], size, arrays[i]);
}
