#include "task/structure/output/individual.h"

#include <string>

#include "screen/matrix/tools.h"

void OutputArrayIntervalSum(std::wstring name, short max) {
    out->Line()->Move();
    pen->Clip("individual_arrays_name")->Text(L": ", name, L", ");
    pen->Clip("individual_arrays_sum")->Text(": ", max);
}

void OutputIndividualArray(std::wstring name, char size, char* array) {
    const wchar_t* numbers = L"%4i";

    out->Line()->Move();
    pen->Text(name, " = ")->FText(numbers, array[0]);

    for (char i = 1; i < size; i++)
        pen->Text(", ")->FText(numbers, array[i]);
}

void OutputMaxArrayElementStart(char size, char T) {
	const wchar_t* numbers = L"%2i";
    out->Slide(3)->Move();
	pen->Clip("individual_source_data");
	pen->Text(": N = ")->FText(numbers, size);
    pen->Text(", T = ")->FText(numbers, T);
}

void OutputMaxArrayElement(char T) {
	out->Slide(2)->Move();
    pen->Clip("individual_max_element")->FText(L": %2i", T);
}
