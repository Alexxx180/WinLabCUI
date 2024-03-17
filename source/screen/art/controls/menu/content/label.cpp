#include "screen/art/controls/menu/content/label.h"
#include <string>

Label :: Label(std::string caption) { 
    m_caption = caption;
}

void Label :: Draw() {
    Pen::ink().Quote(m_caption);
}
