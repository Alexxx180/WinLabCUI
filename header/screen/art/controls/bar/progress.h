#ifndef SCREEN_ART_CONTROLS_BAR_PROGRESS
#define SCREEN_ART_CONTROLS_BAR_PROGRESS

#include "screen/art/drawing.h"
#include "screen/art/types/stapler.h"
#include "screen/art/controls/bar/types/corners.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Progress {
    private:
        Point* m_cursor;
        Range* m_placement;

        unsigned char* m_position;
        unsigned char m_glare, m_slider;

        Separator m_separator;
        Stapler* m_gun;

        // Orientation independent
        void FillBar(char symbol) {
            short i = m_placement->P1.Y;
            short size = m_placement->SumY();

            while (++i < size) {
                VLine(m_cursor, i);
                MoveCursor(m_cursor);
                Draw(symbol);
            }
        }

        void ClearBar(short width) {
            short i = m_placement->P1.Y;
            short size = m_placement->SumY();

            while (++i < size) {
                VLine(m_cursor, i);
                MoveCursor(m_cursor);
                Clean(width);
            }
        }

        // Orientation dependent
        void MoveCarriage(unsigned char position, wchar_t symbol) {
            m_gun->progress(m_cursor, position);
            FillBar(symbol);
        }

    public:
        short Get() { return m_slider; }

        void SetSeparator(Separator* separator) {
            m_separator = *separator;
        }

        Progress* SetCursor(Point* cursor) {
            m_cursor = cursor;
            return this;
        }

        Progress* SetSize(Range* placement) {
            m_placement = placement;
            return this;
        }

        Progress* SetStapler(Stapler* gun) {
            m_gun = gun;
            return this;
        }

        Progress* MemoryPosition(unsigned char* memory) {
            m_position = memory;
            return this;
        }

        Progress* Update(float basis) {
            short start = m_placement->P1.X;
            short end = m_placement->P2.X;

            float location = start + basis * end;
            m_slider = static_cast<short>(location);
            return this;
        }

        void MoveProgress() {
            if (m_slider == *m_position) return;

            short i = m_placement->P1.X;
            short size = m_slider - i;

            HLine(m_cursor, i + 1);
            ClearBar(m_placement->SumX() - i);

            MoveCarriage(m_slider, m_separator.Carriage);

            // size = m_cursor->X - i
            for (i = i + m_glare; i < size; i += m_glare)
                MoveCarriage(i, m_separator.Volume);
        }
};

#endif
