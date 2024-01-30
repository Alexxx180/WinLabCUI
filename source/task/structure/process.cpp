#include "task/structure/process.h"
#include "task/structure/process/task1.h"
#include "task/structure/process/task2.h"

Answer Process(Period task) {
    Answer result;

    result.X = Process1(task.precision.X);
    result.F = Process2(task);

    return result;
}
