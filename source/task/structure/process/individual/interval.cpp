#include "task/structure/process/individual/interval.h"

#include "task/structure/input/common/data.h"
#include "task/structure/output/individual/common.h"
#include "task/structure/output/individual/interval.h"
#include "screen/matrix/tools.h"

void IntervalSum() {
    const char N = 10;
    const char total = 3;

    char A[N], B[N], C[N];
    char* arrays[total] = { A, B, C };

    char r = 0, i = N, j = total;
    short max[total];

    EmptyArray(total, max);
    FillArrays(total, N, arrays);
    ElementsInterval(N);
    ArraysOutput(total, N, arrays);

    for (i = 0; i < N; i++, j = total)
        while (--j >= 0) max[j] += arrays[i][j];

    for (char c = 1; c < total; c++)
        if (max[r] < max[c]) r = c;

	out->Line();
    ElementsSum(arrays[r], max[r]);
}
