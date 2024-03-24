#include "screen/controls/menu/field/option.h"

#include <string>
#include <vector>

#include "screen/matrix/pen.h"
#include "screen/interaction/controller/groups/menu.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/interaction/interaction.h"

Option :: Option() {}
Option :: Option(std::vector<std::string> parameters) {
    Values(parameters);
}

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
    if (!m_edges.Verify(next)) m_selection = next;
    return this;
}

Option* Option :: Values(std::vector<std::string> parameters) {
    m_values = parameters;
    m_edges.Set(0, m_values.size() - 1);
    return this;
}

char Input() {
    return Select(menu_input.controls);
}

char Option :: Query() {
    char code = Input();

    switch (code) {
        case ENTER: code = Action(); break;
        case KEY_UP:
        case KEY_LEFT:
            Previous();
            break;
        case KEY_DOWN:
        case KEY_RIGHT:
            Next();
            break;
        default: break;
    }

    return code;
}
