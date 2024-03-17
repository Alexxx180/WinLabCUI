#ifndef COMMON_TYPES_TIME
#define COMMON_TYPES_TIME

#include <ctime>
#include "common/types.h"

struct TimeMeasure {
    // (0-23):(0-59):(0-59)
    byte hour, minute, second; 
    void Print();
};

struct TimeDiff {
    TimeMeasure Diff(std::tm* x, std::tm* y);
    TimeMeasure CalculateTime(void (*realization)(void));
};

#endif
