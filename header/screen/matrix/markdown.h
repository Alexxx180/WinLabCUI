#ifndef SCREEN_MATRIX_MARKDOWN
#define SCREEN_MATRIX_MARKDOWN

#include <vector>

#include "screen/matrix/pen.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"
#include "screen/art/controls/grid.h"

class Markdown {
    private:
        std::vector<std::vector<Point>> m_forms;
        std::vector<Point> m_pages;
        Range m_origin, m_frame;
        Point m_booker;
        Point* m_next;

    public:
        Markdown* Screen() {
            Grid borders(&m_frame.SwapXY());
            Booker content(m_forms);
            Pen::ink().Append(borders, content);
            m_forms.clear();
            return this;
        }

        Markdown* Form() {
            m_forms.push_back(m_pages);
            m_pages.clear();
            return this;
        }

        Markdown* Page() {
            m_pages.push_back(m_booker);
            return this;
        }

        Markdown* Base(Range* origin) {
            m_origin = *origin;
            return this;
        }

        Markdown* Origin() {
            m_frame = m_origin;
            return this;
        }

        Markdown* ShiftX(Point offset) {
            m_frame.P1.X = m_frame.P2.X + offset.X;
            m_frame.P2.X = m_frame.P1.X + offset.Y;
            return this;
        }

        Markdown* ShiftY(Point offset) {
            m_frame.P1.Y = m_frame.P2.Y + offset.X;
            m_frame.P2.Y = m_frame.P1.Y + offset.Y;
            return this;
        }

        Markdown* P1() {
            m_next = &m_frame.P1;
            return this;
        }

        Markdown* P2() {
            m_next = &m_frame.P2;
            return this;
        }

        Markdown* PinX() {
            m_booker.X = m_next->X;
            return this;
        }

        Markdown* PinY() {
            m_booker.Y = m_next->Y;
            return this;
        }

        Markdown* RatioX(float relation) {
            m_booker.X *= relation;
            return this;
        }

        Markdown* RatioY(float relation) {
            m_booker.Y *= relation;
            return this;
        }

        Markdown* MarginX(unsigned char margin) {
            m_booker.X += margin;
            return this;
        }

        Markdown* MarginY(unsigned char margin) {
            m_booker.Y += margin;
            return this;
        }
};

#endif
