#include "screen/controls/layout/box.h"
#include "screen/drawing/platform.h"

void Box :: Line(Point* cursor, axis_shift pins, wchar_t symbol) {
    byte i = 0, count = m_vertices.size();

    while (i < count) {
        pins(cursor, m_vertices[i++]);
        //wprintf(L"Cursor: %i, %i \n", cursor->X, cursor->Y);
        MoveCursor(cursor);
        Draw(symbol);
    }
}

void Box :: Surround(Stapler* gun) {
    Point cursor;
    byte i = bounds.P1.X, count = bounds.P1.Y;

    gun->progress(&cursor, i);
    Line(&cursor, gun->pins, line.left);

    while (++i < count) {
        gun->progress(&cursor, i);
        Line(&cursor, gun->pins, line.center);
    }

    gun->progress(&cursor, i);
    Line(&cursor, gun->pins, line.right);
    //wprintf(L"Cursor: %i, %i \n", cursor->X, cursor->Y);
}

byte Box :: Count() {
    return m_vertices.size();
}

byte Box :: Rib(const byte current) {
    byte forward = m_vertices[current + 1];
    byte present = m_vertices[current] - 1;
    return forward - present;
}

void Box :: Lines(Stapler* gun) {
    if (!m_vertices.empty()) Surround(gun);
}

Box* Box :: Split(const float proportion) {
    float location = bounds.P2.Y * proportion;
    byte middle = static_cast<byte>(location);
    m_vertices.clear();
    m_vertices.push_back(bounds.P2.X);
    m_vertices.push_back(middle);
    m_vertices.push_back(bounds.P2.Y);
    return this;
}

Box* Box :: Set(const byte count) {
    float location;
    byte column, i = 0;

    m_vertices.clear();
    m_vertices.push_back(bounds.P2.X);

    while (i < count) {
        location = bounds.P2.Y * i++ / count;
        column = static_cast<char>(location);
        m_vertices.push_back(column);
    }

    m_vertices.push_back(bounds.P2.Y);
    return this;
}
