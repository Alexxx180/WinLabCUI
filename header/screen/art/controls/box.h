#ifndef SCREEN_ART_BOX
#define SCREEN_ART_BOX

#include "windows.h"

#include <vector>

#include "common/types.h"
#include "screen/art/drawing.h"

class Box {
private:
    std::vector<short> m_vertices;

    void Line(COORD* cursor, void (*pins)(COORD*, short), wchar_t symbol) {
        short i = -1;
        short count = m_vertices.size();

        while (++i < count) {
            pins(cursor, m_vertices[i]);
            Draw(cursor, symbol);
        }
    }

    void Surround(Stapler* gun) {
        COORD cursor;
        short i = bounds.P1.X;
        short count = bounds.P1.Y;

        gun->progress(&cursor, i);
        Line(&cursor, gun->pins, line.left);

        while (++i < count) {
            gun->progress(&cursor, i);
            Line(&cursor, gun->pins, line.center);
        }

        gun->progress(&cursor, i);
        Line(&cursor, gun->pins, line.right);
    }

public:
    Edges line;
    Range bounds;

    const std::vector<short>& Vertices() {
        return m_vertices;
    }

    void Lines(Stapler* gun) {
        if (!m_vertices.empty())
            Surround(gun);
    }

    short Count() {
        return m_vertices.size();
    }

    short Rib(const short current) {
        short next = m_vertices[current + 1];
        return next - m_vertices[current] - 1;
    }

    Box* Set(const float proportion) {
        short middle = static_cast<short>(bounds.P2.Y * proportion);
        m_vertices.clear();
        m_vertices.push_back(bounds.P2.X);
        m_vertices.push_back(middle);
        m_vertices.push_back(bounds.P2.Y);
        return this;
    }

    Box* Set(const short count) {
        short column, i;

        m_vertices.clear();
        m_vertices.push_back(bounds.P2.X);
        for (i = 1; i < count; i++) {
            column = static_cast<short>(bounds.P2.Y * i / count);
            m_vertices.push_back(column);
        }
        m_vertices.push_back(bounds.P2.Y);
        return this;
    }
};

#endif
