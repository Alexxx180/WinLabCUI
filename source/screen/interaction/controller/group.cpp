#include "screen/interaction/controller/group.h"
#include "screen/matrix/tools.h"

ControllerGroup :: ControllerGroup(std::vector<char> keys, std::map<char, std::wstring> info) {
    controls = keys;
    m_info = info;
}

void ControllerGroup :: Print() {
    byte span = out->back.current->Rows.Rib(0) - 2;
    byte line = 0, page = out->out.current->Columns() - 1;

    out->Page(--page)->Size(1)->Line(line);

    char i = controls.size();

    while (--i >= 0) {
        if (line >= span) {
            out->Page(--page);
            line = 0;
        }

        char key = controls.at(i);

        if (m_info.count(key) > 0) {
            std::wstring info = m_info.at(key);
            out->Line(line++)->Move()->Text(info);
        }
    }
}

void ControllerGroup :: Clear() {
    byte span = out->out.current->Columns();
    char line = out->back.current->Rows.Rib(0) - 2;

    out->Page(0)->Span(span)->Size(1);
    while (--line >= 0) out->Line(line)->Move()->Clear();
}
