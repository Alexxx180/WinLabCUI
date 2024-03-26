#include "screen/controls/matrix/stencil/ruler.h"

void Size(byte lines) { m_lines = lines; }

void Ruler :: Skip(byte& current, char lines, char direction) {
    current = current + lines * direction;
}

void Ruler :: Skip(byte& current, char direction) {
    Skip(current, m_lines, direction);
}
