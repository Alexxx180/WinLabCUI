#ifndef SCREEN_CONTROLS_BAR_PERCENTAGE_PERCENTS
#define SCREEN_CONTROLS_BAR_PERCENTAGE_PERCENTS

#include "common/types.h"

struct Percents {
    const wchar_t* Format = L"%.1f %%";
    byte Width; // Total length of 100.0 % string, including ". %"
    ushort Count; // Decimal percents representation 
    float Max;
    
    void Calculate(float max);
    void Print(float basis);
};

#endif
