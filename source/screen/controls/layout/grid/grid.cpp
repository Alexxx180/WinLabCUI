#include "screen/controls/layout/grid/grid.h"

#include <vector>

#include "screen/drawing/drawing.h"
#include "screen/drawing/platform.h"

void Grid :: Crosses() {
    Point cursor, cells;
    const std::vector<byte>& y = Rows.Vertices;
    const std::vector<byte>& x = Columns.Vertices;

    short r = 0, c = 0;
    cells = {
        static_cast<byte>(y.size() - 1),
        static_cast<byte>(x.size() - 1)
    };

    while (++r < cells.X) {

        while (++c < cells.Y) {
            cursor.Y = y.at(r);
            cursor.X = x.at(c);
            MoveCursor(&cursor);
            Draw(form_edges.cross);
        }

    }
}

byte Grid :: BasePoint() { return m_sizes.P1.Y; }

Point Grid :: TopAnchor() {
    return { m_sizes.P1.X, m_sizes.P2.X };
}

Point Grid :: BottomAnchor() {
    return { m_sizes.P1.Y, m_sizes.P2.Y };
}

Angles Grid :: TopAngles() { return form_edges.top; };

Angles Grid :: BottomAngles() { return form_edges.bottom; };

Grid :: Grid() {}

Grid :: Grid(Range* sizes) {
    m_sizes = *sizes;
    Rows.bounds = *sizes;
    Columns.bounds = sizes->Swap();

    Rows.line = form_edges.horizontal;
    Columns.line = form_edges.vertical;

    Rows.Set(0);
    Columns.Set(0);
}

Grid* Grid :: Show() {
    Stapler m_gun = { HLine, VLine };
    Rows.Lines(&m_gun);
    m_gun.Set(VLine, HLine);
    Columns.Lines(&m_gun);

    Crosses();
    DrawAngles();
    return this;
}
