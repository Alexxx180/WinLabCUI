#include "common/types/time.h"

#include <stdio.h>
#include <ctime>

#include "common/types.h"

void TimeMeasure :: Print() {
    wprintf(L"%i:%02i:%02i", hour, minute, second);
}

TimeMeasure TimeDiff :: Diff(std::tm* x, std::tm* y) {
    byte sec, min, hour;
    hour = static_cast<byte>(y->tm_hour - x->tm_hour);
    min = static_cast<byte>(y->tm_min - x->tm_min);
    sec = static_cast<byte>(y->tm_sec - x->tm_sec);
    return { hour, min, sec };
}

TimeMeasure TimeDiff :: CalculateTime(void (*realization)(void)) {
    std::tm before, after;
    std::time_t p1 = p2 = std::time(0);

    before = std::localtime(&p1);
    realization();
    after = std::localtime(&p2);
    return Diff(before, after);
}
