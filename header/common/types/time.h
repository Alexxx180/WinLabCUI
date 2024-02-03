#ifndef COMMON_TYPES_TIME
#define COMMON_TYPES_TIME

#include <stdio.h>
#include <ctime>

struct TimeMeasure {
    unsigned char hour, minute, second; /* (0-23):(0-59):(0-59) */

    void Print() {
        wprintf(L"%i:%02i:%02i", hour, minute, second);
    }
};

struct TimeDiff {
    TimeMeasure Diff(std::tm* x, std::tm* y) {
        unsigned char sec, min, hour;

        hour = static_cast<unsigned char>(y->tm_hour - x->tm_hour);
        min = static_cast<unsigned char>(y->tm_min - x->tm_min);
        sec = static_cast<unsigned char>(y->tm_sec - x->tm_sec);

        TimeMeasure result = { hour, min, sec };
        return result;
    }

    TimeMeasure CalculateTime(void (*realization)(void)) {
        std::time_t current;

        current = std::time(0);
        std::tm* before = std::localtime(&current);

        realization();

        current = std::time(0);
        std::tm* after = std::localtime(&current);

        return Diff(before, after);
    }
};

#endif
