#include "screen/art/controls/menu/content/option.h"

#include <string>
#include <vector>

#include "screen/matrix/pen.h"
#include "screen/art/controls/menu/navigation.h"

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
    if (m_edges.Verify(next)) return this;

	m_selection = next;
    return this;
}

Option* Option :: Values(std::vector<std::string> parameters) {
    m_values = parameters;
    m_edges.Set(0, m_values.size() - 1);
    return this;
}

char Option :: Query() {
    char code = Select(menu_input_keys);
	//wprintf(L"Code: %i", code);

    switch (code) {
        case ENTER:
            //wprintf(L"B: %i", m_code);
            code = Action();
	        //wprintf(L"A: %i", m_code);
            break;
        case KEY_UP:
        case KEY_LEFT:
        	//wprintf(L"LEFT");
            Previous();
            break;
        case KEY_DOWN:
        case KEY_RIGHT:
    	    //wprintf(L"RIGHT");
            Next();
            break;
        default:
            break;
    }

    return code;
}
