#ifndef SCREEN_MATRIX_MARKDOWN
#define SCREEN_MATRIX_MARKDOWN

#include <vector>

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/change/shifter.h"
#include "screen/controls/bar/bar.h"
#include "screen/controls/matrix/screen.h"
#include "screen/controls/matrix/pen.h"
#include "screen/controls/matrix/stencil.h"
#include "screen/controls/matrix/stencil/mapper.h"

class Markdown {
    private:
        std::vector<Mapper> m_forms;
        std::vector<Point> m_pages;
        Range m_origin, m_next;
        Point m_current;

        Shifter m_positions[2];

        Markdown* Place(Shifter* pos, byte p1, byte p2);

    public:
        const Point& Cursor = m_current;

        Markdown();
        Markdown* Clear();
        Bar ProgressBar();
        Screen Result();
        Markdown* Form();
        Markdown* Page();
        Markdown* Base(Range* origin);
        Markdown* Origin();
        Markdown* Shift(byte flow, byte p2, byte size);
        Markdown* Flatten(byte flow, byte margin, float ratio);
        Markdown* Top();
        Markdown* Bot();
        Markdown* Top(byte flow);
        Markdown* Bot(byte flow);
        Markdown* Relate(byte flow, float relation);
        Markdown* Split(byte flow, float ratio);
        Markdown* Margin(byte flow, byte margin);
};

#endif
