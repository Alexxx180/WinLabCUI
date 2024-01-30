#include "task/structure/process/task1.h"

#include <math.h>

short precision, sign = 1;

double FuncX(short n) {
    short axis = (++sign >= 3) ? 1 : -1;
    return (n >= precision) ? sqrt(8)
        : sqrt(8 + axis * FuncX(n + 1));
}

double Process1(unsigned short input) {
    precision = input;
    return FuncX(0);
}
