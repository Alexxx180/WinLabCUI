#include "screen/interaction/controller/group.h"
#include "screen/matrix/tools.h"

ControllerGroup :: ControllerGroup(std::vector<char> keys, std::map<char, std::wstring> info) {
    controls = keys;
    m_info = info;
}

void ControllerGroup :: Print() {
    byte span = out->back.current->Rows.Rib(0) - 2;
    byte line = 0, page = out->out.current->Columns();

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
