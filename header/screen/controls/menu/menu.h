#ifndef SCREEN_ART_CONTROLS_MENU_MENU
#define SCREEN_ART_CONTROLS_MENU_MENU

#include "screen/matrix/types/point.h"
#include "screen/art/controls/menu/menuitem.h"

class Menu : public MenuItem {
    public:
        Menu* Expand();
        Menu* Vertical(bool direction);
        Menu* SetItems();
        Menu* Add(MenuItem* item);
		void Index(Point position);
};

#endif
