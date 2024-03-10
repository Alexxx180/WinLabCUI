#ifndef SCREEN_ART_CONTROLS_BAR_TYPES_PERCENTS
#define SCREEN_ART_CONTROLS_BAR_TYPES_PERCENTS

#include <string>

struct Percents {
    const wchar_t* Format = L"%.1f %%";
    // Total length of 100.0 % string, including ". %"
    unsigned char Width;
    // Decimal percents representation
    unsigned short Count;
    float Max;
    
    void Calculate(float max) {
        Max = max;
        Count = static_cast<unsigned short>(max * 10);

        std::string percentage = std::to_string(Count);
        Width = percentage.length() + 3;
    }
};

#endif