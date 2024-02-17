#include "task/structure/process/individual.h"

#include <string>

#include "task/structure/input/common/data.h"
#include "task/structure/output/individual.h"
#include "screen/matrix/pen.h"

#define N 10

char A[N], B[N], C[N];

void FillArray(char size, char* array) {
    char i = N;
    while (--i > 0)
        array[i] = randomc.Standard();
}

void AbsoluteInterval() {
    char current = 0, i = N;
    short max[3];

    max[0] = max[1] = max[2] = 0;

    std::wstring name[3] = { L"A", L"B", L"C" };

    FillArray(A); FillArray(B); FillArray(C);

    Pen::ink().Text("D1 = 0, ")->Text("D2 = ");
    Pen::ink().Text(randomc.limits.end);
    Pen::ink().screen->Line();

    OutputIndividualArray(name[0], N, A);
    OutputIndividualArray(name[1], N, B);
    OutputIndividualArray(name[2], N, C);

    while (--i > 0) {
        max[0] += A[i];
        max[1] += B[i];
        max[2] += C[i];
    }

    for (char c = 1; c < 3; c++)
        if (max[current] < max[c]) current = c;

    OutputArrayIntervalSum(name[current], max[current]);
}

void NumberOfMaxElement() {
    char T = 15;
    OutputMaxArrayElementStart(T);

    FillArray(A);

    for (char i = 0; i < N; i++)
        if (A[i] > T) T = A[i];

    OutputIndividualArray(L"A", N, A);
    OutputMaxArrayElement(T);
}

void StartIndividual() {
    Pen::ink().Quote("individual_arrays")
    AbsoluteInterval();
    NumberOfMaxElement();
}
