#include "screen/interaction/controller/group.h"
#include "screen/matrix/pen.h"

ControllerGroup :: ControllerGroup(std::vector<char> keys, std::map<byte, std::wstring> info) {
    controls = keys;
    m_info = info;
}

void ControllerGroup :: Print(byte form) {
    Pen::ink().Target(form);

    byte line = 0, page = 0;
    byte size = controls.size();
    byte span = Pen::ink().back->Rows.Rib(0);

    for (byte i = 0; i < size; i++) {
        if (line > span) {
            Pen::ink().screen->Page(++page);
            line = 0;
        }

        if (m_info.count(i) > 0) {
            Pen::ink().screen->Line(line++);

            std::wstring key = m_info.at(i);

            Pen::ink().screen->Move();
            Pen::ink().Text(key);
        }
    }
}
