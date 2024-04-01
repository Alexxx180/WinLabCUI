#include "screen/controls/menu/field/label.h"

#include <string>

#include "common/codes.h"
#include "screen/controls/matrix/pen.h"
#include "screen/interaction/controller/keyboard.h"

Label :: Label(std::string caption) { 
    m_caption = caption;
}

void Label :: Draw() {
    Pen::ink().Clip(m_caption);
}

char Label :: Input() { return UNDEFINED; }
char Label :: Action() { return UNDEFINED; }

void Label :: Previous() {}
void Label :: Next() {}
void Label :: Climb() {}
void Label :: Slide() {}
void Label :: First() {}
void Label :: Last() {}
