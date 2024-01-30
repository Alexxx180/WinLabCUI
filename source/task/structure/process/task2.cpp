#include "task/structure/process.h"

#include <math.h>

#include <vector>

#include "common/types.h"
#include "screen/interaction.h"
#include "output/format/pen.h"

#include <dos.h>

short precision;
double calculation, x;

double ArctgFormula(short n) {

    short axis = pow(-1, n);
    double pattern = 2 * n + 1;

    return axis * pow(x, pattern) / pattern;
}

void ArctgIterative() {
    double result = 0;

    for (short n = 0; n < precision; n++)
        result += ArctgFormula(n);

    calculation = result;
}

double ArctgRecursiveIteration(short n) {
    return (n >= precision) ? ArctgFormula(n)
        : ArctgRecursiveIteration(n + 1) + ArctgFormula(n);
}

void ArctgRecursive() {
    calculation = ArctgRecursiveIteration(0);
}

void ArctgLegacy() {
    calculation = atan(x);
}

dostime CalculateTime(void (*realization)(void)) {
    dostime before, after, result;
    _dos_gettime(&before);
    realization();
    _dos_gettime(&after);

    result = Task2::Diff(before, after);
    return result;
}

Task2 Process2(short count) {
    precision = count;
    Task2 result;

    result.legacy = CalculateTime(ArctgLegacy);
    result.result.X = calculation;

    result.recursive = CalculateTime(ArctgRecursive);
    result.result.Y = calculation;

    result.iterative = CalculateTime(ArctgIterative);
    result.result.Z = calculation;
    return result;
}

    //Pen::ink().status.SetDivisions(count)->Show();
    //Pen::ink().status.ProgressData(++i);
