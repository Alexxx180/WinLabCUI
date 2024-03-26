#include "screen/controls/matrix/stencil/ruler.h"

void Ruler :: Size(byte lines) {
    m_lines = lines;
}

void Ruler :: Skip(byte& current, char lines) {
    current = current + lines;
}

void Ruler :: Jump(byte& current, char direction) {
    Skip(current, m_lines * direction);
}
