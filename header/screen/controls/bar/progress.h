#ifndef SCREEN_CONTROLS_BAR_PROGRESS
#define SCREEN_CONTROLS_BAR_PROGRESS

#include "common/types.h"
#include "screen/drawing/constructs/outlines/separator.h"
#include "screen/matrix/types/change/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Progress {
    private:
        Point* m_cursor;
        Range* m_placement;

        byte* m_position;
        byte m_glare, m_slider;

        Separator m_separator;
        Stapler* m_gun;

        wchar_t m_symbol;
        short m_width;

        // Orientation independent
        void Display();
        void Clear();
        void Fill(void (Progress::*operation)());
        // Orientation dependent
        void MoveCarriage(byte position);

    public:
        short Get();
        void SetSeparator(Separator* separator);
        Progress* SetCursor(Point* cursor);
        Progress* SetSize(Range* placement);
        Progress* SetStapler(Stapler* gun);
        Progress* MemoryPosition(byte* memory); 
        Progress* Update(float basis);
        void MoveProgress(); 
};

#endif
