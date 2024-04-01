#include "task/structure/output/individual/common.h"

#include "screen/matrix/tools.h"

void ArrayOutput(std::wstring name, char size, char* array) {
    const wchar_t* no = L"%4i";

    char first = array[0];
    out->Line()->Move();
    out->Text(name, L" = ");
    out->FText(no, first);

    for (char i = 1; i < size; i++)
        out->Text(L", ")->FText(no, array[i]);
}

void ArraysOutput(std::wstring* names, char count, char size, char** arrays) {
    for (char i = 0; i < count; i++)
        ArrayOutput(names[i], size, arrays[i]);
}
