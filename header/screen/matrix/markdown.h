#ifndef SCREEN_MATRIX_MARKDOWN
#define SCREEN_MATRIX_MARKDOWN

#include <vector>

#include "screen/art/drawing.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/booker.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"

class Markdown {
    private:
        std::vector<std::vector<Point>> m_forms;
        std::vector<Point> m_pages;
        Range m_origin, m_frame;
        Point m_booker;
        Point* m_next;

        Shifter[2] m_positions = { 
            { HPoint, HLine, HRatio },
            { VPoint, VLine, VRatio }
        };

    public:
        Markdown* Screen(); 
        Markdown* Form(); 
        Markdown* Page(); 
        Markdown* Base(Range* origin); 
        Markdown* Origin(); 
        Markdown* Shift(byte flow, Point offset); 
        Markdown* Top(); 
        Markdown* Bottom(); 
        Markdown* Pin(byte flow); 
        Markdown* Ratio(byte flow, float relation); 
        Markdown* Margin(byte flow, byte margin); 
};

#endif
