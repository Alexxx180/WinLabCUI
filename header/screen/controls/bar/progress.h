#ifndef SCREEN_CONTROLS_BAR_PROGRESS
#define SCREEN_CONTROLS_BAR_PROGRESS

#include "common/types.h"
#include "screen/drawing/types/constructs/outlines/separator.h"
#include "screen/matrix/change/stapler.h"
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
        short width;

        // Orientation independent
        void Draw();
        void Clear();
        void Fill(void (*operation)());
        // Orientation dependent
        void MoveCarriage(byte position, wchar_t symbol);

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
