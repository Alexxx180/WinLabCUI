#include "screen/controls/matrix/stencil/ruler.h"

void Ruler :: Size(byte lines) {
    m_lines = lines;
}

byte Ruler :: Skip(byte current, char lines) {
    return current + lines;
}

byte Ruler :: Jump(byte current, char direction) {
    return Skip(current, m_lines * direction);
}

short Ruler :: Diff(std::vector<Point>& basis, Book next) {
    byte old = next.Pages;
    byte mark = next.Mark;

    next.Split(basis.size());
    next.Pages += old;

    byte heading = next.Map(basis);
    byte present = basis.at(mark).X;

    return heading - present;
}
