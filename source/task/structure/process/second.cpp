#include "task/structure/process/second.h"

#include <string>

#include "task/structure/input/common/data.h"
#include "task/structure/output/individual.h"
#include "screen/matrix/pen.h"

#define N 10

char A[N], B[N], C[N];

void AbsoluteInterval() {
    char current = 0, i = N;
    short max[3];

    max[0] = max[1] = max[2] = 0;

    std::wstring name[3] = { L"A", L"B", L"C" };

    FillArray(N, A); FillArray(N, B); FillArray(N, C);

	pen->Clip("individual_source_data");
	pen->Text(": N = ", N, ", D1 = 0, D2 = ");
    pen->FText(L"%i", randomc.limits.end);

	out->Line();
    OutputIndividualArray(name[0], N, A);
    OutputIndividualArray(name[1], N, B);
    OutputIndividualArray(name[2], N, C);

    while (--i >= 0) {
        max[0] += A[i];
        max[1] += B[i];
        max[2] += C[i];
    }

    for (char c = 1; c < 3; c++)
        if (max[current] < max[c]) current = c;

	Pen::ink().screen->Line();
    OutputArrayIntervalSum(name[current], max[current]);
}

void NumberOfMaxElement() {
    char T = 15;
    OutputMaxArrayElementStart(N, T);

    FillArray(N, A);

    for (char i = 0; i < N; i++)
        if (A[i] > T) T = A[i];

	out->Line();
    OutputIndividualArray(L"A", N, A);
    OutputMaxArrayElement(T);
}

void StartIndividual() {
	layer->Target(MAIN);
	out->Page(0)->Size(1)->Line(0)->Move();
    pen->Clip("individual_arrays");
    AbsoluteInterval();
    NumberOfMaxElement();
    layer->Target(MENU);
	out->Move();
}
