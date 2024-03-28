#include "task/forms/defaults/cui/cui.h"

#include "task/forms/defaults/cui/markdown/markdown.h"
#include "task/forms/defaults/cui/screens/menu/menu.h"
#include "task/forms/defaults/cui/tools/tools.h"

void CharacterUserInterface() {
    ApplyMarkdown();
    MenuInit();
    InitTools();
}
