#ifndef SCREEN_ART_GRID
#define SCREEN_ART_GRID

#include <vector>

#include "screen/art/controls/box.h"
#include "screen/art/drawing.h"
#include "screen/art/types/frame.h"
#include "screen/matrix/types/range.h"
#include "screen/matrix/types/point.h"

class Grid : public Panel {
private:
    Range m_sizes;

    void Crosses() {
        Point cursor, cells;

        const std::vector<unsigned char>& y = Rows.Vertices();
        const std::vector<unsigned char>& x = Columns.Vertices();

        short r = 0, c = 0;
        cells = { y.size() - 1, x.size() - 1 };

        while (++r < cells.X) {

            while (++c < cells.Y) {
                cursor.Y = y.at(r);
                cursor.X = x.at(c);
                MoveCursor(&cursor);
                Draw(form_edges.cross);
            }

        }
    }

protected:
    unsigned char BasePoint() { return m_sizes.P1.X; }

    Point TopAnchor() { return { m_sizes.P1.Y, m_sizes.P2.X }; }
    Point BottomAnchor() { return { m_sizes.P2.Y, m_sizes.P1.X }; }

    Angles TopAngles() { return form_edges.top; };
    Angles BottomAngles() { return form_edges.bottom; };

public:
    Box Rows;
    Box Columns;

    Grid(Range* sizes) {
        m_sizes = *sizes;
        Rows.bounds = *sizes;
        Columns.bounds = sizes->Swap();
        
        Rows.line = form_edges.horizontal;
        Columns.line = form_edges.vertical;

        short count = 0;
        Rows.Set(count);
        Columns.Set(count);
    }

    Grid* Show() {
        Stapler m_gun = { HLine, VLine };
        Rows.Lines(&m_gun);

        m_gun.Set(VLine, HLine);
        Columns.Lines(&m_gun);

        Crosses();
        DrawAngles();
        return this;
    }
};

#endif
