#ifndef SCREEN_ART_CONTROLS_BAR_PERCENTAGE
#define SCREEN_ART_CONTROLS_BAR_PERCENTAGE

#include "screen/art/controls/bar/types/percents.h"
#include "screen/art/drawing.h"
#include "screen/art/types/stapler.h"
#include "screen/matrix/types/point.h"

class Percentage {
private:
    const Percents m_percentage(100.0f);
    unsigned char m_offset;
    unsigned char* m_position;
    Point* m_cursor;
    Stapler* m_gun;

    void PercentagePosition() {
        m_gun->pins(m_cursor, m_offset);
        m_gun->progress(m_cursor, m_position);
    }

    void ClearPercentage() {
        if (*m_position < 0) return;

        PercentagePosition();
        MoveCursor(m_cursor);
        Clean(m_percentage.Width);
    }

    void SetPercentage(float basis) {
        PercentagePosition();

        float max = m_percentage.Max;
        float result = basis * max;

        MoveCursor(m_cursor);
        wprintf(m_percentage.Format, result);
    }

public:
    unsigned short Count() { return m_percentage.Count; }

    void SetOffset(short offset) { m_offset = offset; }

    Percentage* SetCursor(Point* cursor) {
        m_cursor = cursor;
        return this;
    }

    Percentage* SetStapler(Stapler* gun) {
        m_gun = gun;
        return this;
    }

    void Update(float basis, unsigned char position) {
        ClearPercentage();
        *m_position = position;
        SetPercentage(basis);
    }
};

#endif
