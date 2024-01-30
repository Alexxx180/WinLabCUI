#ifndef SCREEN_ART_GRID
#define SCREEN_ART_GRID

#include <vector>

#include "screen/art/controls/box.h"
#include "screen/art/drawing.h"
#include "common/types.h"

#include <conio.h>

class Grid {
private:

    void Crosses() {
        COORD cursor;

        const std::vector<short>& y = Rows.Vertices();
        const std::vector<short>& x = Columns.Vertices();

        short r = 0, c = 0;
        short rcount = y.size() - 1, ccount = x.size() - 1;

        while (++r < rcount) {

            while (++c < ccount) {
                cursor.Y = y.at(r);
                cursor.X = x.at(c);
                Draw(&cursor, form_edges.cross);
            }

        }
    }

public:
    Box Rows;
    Box Columns;

    Grid(Range* sizes) {
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

        COORD cursor = { Rows.bounds.P1.X , Rows.bounds.P2.X };
        Draw(&cursor, form_edges.top.left);

        HLine(&cursor, Rows.bounds.P1.Y);
        Draw(&cursor, form_edges.top.right);

        VLine(&cursor, Rows.bounds.P2.Y);
        Draw(&cursor, form_edges.bottom.right);

        HLine(&cursor, Rows.bounds.P1.X);
        Draw(&cursor, form_edges.bottom.left);
        return this;
    }
};

#endif
