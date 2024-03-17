#include "screen/art/controls/menu/content/option.h"

#include <string>
#include <vector>

#include "screen/matrix/pen.h"
#include "screen/art/controls/menu/navigation.h"

void Option :: Previous() {
    Current(m_selection - 1);
    Draw();
}

void Option :: Next() {
    Current(m_selection + 1);
    Draw();
}

char Option :: Action() {
    Next();
    return ENTER;
}

void Option :: Draw() {
    Pen::ink().Quote(m_values[m_selection]);
}

short Option :: Choice() {
    return m_selection;
}

Option* Option :: Current(short next) {
    if (m_edges.Verify(next)) return this;

	m_selection = next;
    return this;
}

Option* Option :: Values(std::vector<std::string> values) {
    m_values = values;
    m_edges.Set(0, m_values.size() - 1);
    return this;
}
