#include "screen/interaction/controller/group.h"
#include "screen/matrix/tools.h"

ControllerGroup :: ControllerGroup(std::vector<char> keys, std::map<byte, std::wstring> info) {
    controls = keys;
    m_info = info;
}

void ControllerGroup :: Print(byte form) {
    layer->Target(form);

    byte line = 0, page = 0;
    byte size = controls.size();
    byte span = back->Rows.Rib(0);

    for (byte i = 0; i < size; i++) {
        if (line > span) {
            out->Page(++page);
            line = 0;
        }

        if (m_info.count(i) > 0) {
            out->Line(line++);

            std::wstring key = m_info.at(i);

            out->Move();
            pen->Text(key);
        }
    }
}
