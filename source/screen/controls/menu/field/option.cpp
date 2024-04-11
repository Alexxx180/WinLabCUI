#include "screen/controls/menu/field/option.h"

#include <string>
#include <vector>

#include "screen/matrix/tools.h"
#include "screen/interaction/controller/groups/menu.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/interaction/interaction.h"

Option :: Option() {}
Option :: Option(std::vector<std::string> parameters) {
    Values(parameters);
}

void Option :: Climb() {}
void Option :: Slide() {}

void Option :: First() {
    Current(m_edges.start)->Draw();
}

void Option :: Last() {
    Current(m_edges.end)->Draw();
}

void Option :: Previous() {
    Current(m_selection - 1)->Draw();
}

void Option :: Next() {
    Current(m_selection + 1)->Draw();
}

char Option :: Action() {
    Next();
    return ENTER;
}

void Option :: Draw() {
    out->Move()->Clear()->Move();
    out->Clip(m_values[m_selection]);
}

short Option :: Choice() {
    return m_selection;
}

Option* Option :: Current(short next) {
    if (!m_edges.Deny(next))
        m_selection = next;
    return this;
}

Option* Option :: Values(std::vector<std::string> parameters) {
    m_values = parameters;
    m_edges.Set(0, m_values.size() - 1);
    return this;
}

char Option :: Input() {
    return Select(menu_input.controls);
}
