#ifndef TASK_STRUCTURE_PROCESS_TASK2
#define TASK_STRUCTURE_PROCESS_TASK2

#include <dos.h>

double ArctgFormula(short n);
void ArctgIterative();
double ArctgRecursiveIteration(short n);
void ArctgRecursive();
void ArctgLegacy();
dostime CalculateTime(void (*realization)(void));
Task2 Process2(short count);

#endif
