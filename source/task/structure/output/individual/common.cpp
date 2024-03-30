#include "task/structure/output/individual/common.h"

#include "common/nameof.h"
#include "screen/matrix/tools.h"

void ArrayOutput(char size, char* array) {
    const wchar_t* no = L"%4i";

    std::string name = NAMEOF(array);
    out->Line()->Move();
    pen->Text(name)->Text(" = ")->FText(no, array[0]);

    for (char i = 1; i < size; i++)
        pen->Text(", ")->FText(no, array[i]);
}

void ArraysOutput(char count, char size, char** arrays) {
    for (char i = 0; i < count; i++) ArrayOutput(size, arrays[i]);
}