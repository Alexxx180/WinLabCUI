#ifndef SCREEN_MATRIX_MARKDOWN
#define SCREEN_MATRIX_MARKDOWN

#include <vector>

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/change/shifter.h"
#include "screen/controls/matrix/screen.h"
#include "screen/controls/matrix/pen.h"
#include "screen/controls/matrix/stencil.h"

static const byte X = 0, Y = 1;

class Markdown {
    private:
        std::vector<std::vector<Point>> m_forms;
        std::vector<Point> m_pages;
        Range m_origin, m_frame;
        Point m_booker;
        Point* m_next;

        Shifter m_positions[2];

    public:
        Markdown();
        Markdown* Clear();
        Screen Screen();
        Markdown* Form(); 
        Markdown* Page(); 
        Markdown* Base(Range* origin); 
        Markdown* Origin(); 
        Markdown* Shift(byte flow, Point offset); 
        Markdown* Top(); 
        Markdown* Bot(); 
        Markdown* Pin(byte flow); 
        Markdown* Relate(byte flow, float relation); 
        Markdown* Margin(byte flow, byte margin); 
};

#endif
