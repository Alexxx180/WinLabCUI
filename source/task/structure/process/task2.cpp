#include "task/structure/process/task2.h"

#include <math.h>

#include <vector>

#include "common/types.h"
#include "screen/interaction.h"
#include "output/format/pen.h"

short accuracy;
double calculation, x;

double ArctgFormula(short n) {

    short axis = pow(-1, n);
    double pattern = 2 * n + 1;

    return axis * pow(x, pattern) / pattern;
}

void ArctgIterative() {
    double result = 0;

    for (short n = 0; n < accuracy; n++)
        result += ArctgFormula(n);

    calculation = result;
}

double ArctgRecursiveIteration(short n) {
    return (n >= accuracy) ? ArctgFormula(n)
        : ArctgRecursiveIteration(n + 1) + ArctgFormula(n);
}

void ArctgRecursive() {
    calculation = ArctgRecursiveIteration(0);
}

void ArctgLegacy() {
    calculation = atan(x);
}

Task2 Process2(Period* task) {
    accuracy = task->precision.Y;
    x = task->x;
    Task2 result;

    result.legacy = result.CalculateTime(ArctgLegacy);
    result.result.X = calculation;

    result.recursive = result.CalculateTime(ArctgRecursive);
    result.result.Y = calculation;

    result.iterative = result.CalculateTime(ArctgIterative);
    result.result.Z = calculation;
    return result;
}
