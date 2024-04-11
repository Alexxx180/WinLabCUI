#include "task/forms/defaults/cui/screens/menu/menu.h"

#include "task/forms/defaults/cui/screens/menu/main.h"
#include "task/forms/defaults/cui/screens/menu/array.h"
#include "task/forms/defaults/cui/screens/menu/individual.h"

void MenuInit() {
    MainMenu();
    ArrayMenu();
    IndividualMenu();
}
