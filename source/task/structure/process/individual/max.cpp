#include "task/structure/process/individual/max.h"

#include "task/structure/input/common/data.h"
#include "task/structure/output/individual/common.h"
#include "task/structure/output/individual/max.h"
#include "screen/matrix/tools.h"

const char N = 10;

char A[N];

void MaxElement() {
    char T = 15;
    MaxHeader(N, T);
    FillArray(N, A);

    for (char i = 0; i < N; i++)
        if (A[i] > T) T = A[i];

	out->Line();
    ArrayOutput(N, A);
    MaxResult(T);
}
