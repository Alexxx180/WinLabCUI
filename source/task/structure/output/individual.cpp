#include "task/structure/output/individual.h"

#include <string>

#include "screen/matrix/pen.h"

void OutputArrayIntervalSum(std::wstring name, short max) {
    Pen::ink().Quote("individual_arrays_name");
    Pen::ink().Text(name)->Text(L", ");
    Pen::ink().Quote("individual_arrays_sum");
    Pen::ink().Text(max);
}

void OutputIndividualArray(std::wstring name, char size, char* array) {
    const wchar_t* numbers = L"%4i";

    Pen::ink().Text(name)->Text(" = ");
    Pen::ink().FText(numbers, array[0]);

    for (char i = 1; i < size; i++)
        Pen::ink().Text(", ")->FText(numbers, array[i]);

    Pen::ink().screen->Line();
}

void OutputMaxArrayElementStart(char T) {
    Pen::ink().Text(L"T = ")->FText(L"%2i", T);
    Pen::ink().screen->Line();
}

void OutputMaxArrayElement(char T) {
    Pen::ink().Quote("individual_max_element")->FText(L"%2i", T);
}
