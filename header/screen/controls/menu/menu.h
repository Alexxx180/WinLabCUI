#ifndef SCREEN_CONTROLS_MENU_MENU
#define SCREEN_CONTROLS_MENU_MENU

#include "screen/matrix/types/point.h"
#include "screen/controls/menu/menuitem.h"

struct Menu : public MenuItem {
    Menu* Expand();
    Menu* Vertical(bool direction);
    Menu* SetItems();
    Menu* Add(MenuItem* item);
    void Index(Point position);
};

#endif
