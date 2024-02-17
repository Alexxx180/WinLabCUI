#ifndef SCREEN_ART_BOX
#define SCREEN_ART_BOX

#include <vector>

#include "screen/art/drawing.h"
#include "screen/art/types/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Box {
private:
    std::vector<unsigned char> m_vertices;

    void Line(Point* cursor, void (*pins)(Point*, unsigned char), wchar_t symbol) {
        short i = -1, count = m_vertices.size();

        while (++i < count) {
            pins(cursor, m_vertices[i]);
            MoveCursor(cursor);
            Draw(symbol);
        }
    }

    void Surround(Stapler* gun) {
        Point cursor;
        unsigned char i = bounds.P1.X, count = bounds.P1.Y;

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

    const std::vector<unsigned char>& Vertices() { return m_vertices; }

    unsigned char Count() { return m_vertices.size(); }

    unsigned char Rib(const unsigned char current) {
        unsigned char next, previous;
        next = m_vertices[current + 1];
        previous = m_vertices[current] - 1;
        return next - previous;
    }

    void Lines(Stapler* gun) {
        if (!m_vertices.empty())
            Surround(gun);
    }

    Box* Split(const float proportion) {
        float location = bounds.P2.Y * proportion;
        unsigned char middle = static_cast<unsigned char>(location);
        m_vertices.clear();
        m_vertices.push_back(bounds.P2.X);
        m_vertices.push_back(middle);
        m_vertices.push_back(bounds.P2.Y);
        return this;
    }

    Box* Set(const unsigned char count) {
        float location;
        unsigned char column, i = -1;

        m_vertices.clear();
        m_vertices.push_back(bounds.P2.X);

        while (++i < count) {
            location = bounds.P2.Y * i / count;

            column = static_cast<unsigned char>(location);

            m_vertices.push_back(column);
        }

        m_vertices.push_back(bounds.P2.Y);
        return this;
    }
};

#endif
