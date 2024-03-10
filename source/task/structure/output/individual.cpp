#include "task/structure/output/individual.h"

#include <string>

#include "common/texts/common.h"
#include "screen/matrix/pen.h"

void OutputArrayIntervalSum(std::wstring name, short max) {
    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(texts["individual_arrays_name"]);
    Pen::ink().Text(": ")->Text(name)->Text(L", ");
    Pen::ink().Text(texts["individual_arrays_sum"]);
    Pen::ink().Text(": ")->Text(max);
}

void OutputIndividualArray(std::wstring name, char size, char* array) {
    const wchar_t* numbers = L"%4i";

    Pen::ink().screen->Line()->Move();
    Pen::ink().Text(name)->Text(" = ");
    Pen::ink().FText(numbers, array[0]);

    for (char i = 1; i < size; i++)
        Pen::ink().Text(", ")->FText(numbers, array[i]);
}

void OutputMaxArrayElementStart(char size, char T) {
	const wchar_t* numbers = L"%2i";
    Pen::ink().screen->Line()->Line()->Line()->Move();
	Pen::ink().Quote("individual_source_data");
	Pen::ink().Text(": N = ")->FText(numbers, size);
    Pen::ink().Text(", T = ")->FText(numbers, T);
}

void OutputMaxArrayElement(char T) {
	Pen::ink().screen->Line()->Line()->Move();
    Pen::ink().Quote("individual_max_element")->FText(L": %2i", T);
}
