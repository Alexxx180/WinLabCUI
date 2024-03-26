#ifndef SCREEN_CONTROLS_BAR_PERCENTAGE_PERCENTAGE
#define SCREEN_CONTROLS_BAR_PERCENTAGE_PERCENTAGE

#include "common/types.h"
#include "screen/controls/bar/percentage/percents.h"
#include "screen/matrix/types/change/stapler.h"
#include "screen/matrix/types/point.h"

class Percentage {
private:
    Percents m_percentage;

    byte m_offset;
    byte* m_position;

    Point* m_cursor;
    Stapler* m_gun;

    void PercentagePosition();
    void ClearPercentage();
    void SetPercentage(float basis);

public:
    Percentage();
    ushort Count();
    void SetOffset(byte offset);
    Percentage* MemoryPosition(byte* memory);
    Percentage* SetCursor(Point* cursor);
    Percentage* SetStapler(Stapler* gun);
    void Update(float basis, byte position);
};

#endif
