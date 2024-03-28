#include "screen/controls/menu/field/label.h"

#include <string>

#include "screen/matrix/tools.h"
#include "screen/interaction/controller/keyboard.h"

Label :: Label(std::string caption) { 
    m_caption = caption;
}

void Label :: Draw() {
    pen->Clip(m_caption);
}

char Label :: Input() { return ESC; }
