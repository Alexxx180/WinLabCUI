#ifndef SCREEN_ART_CONTROLS_MENU_MENU
#define SCREEN_ART_CONTROLS_MENU_MENU

#include <vector>
#include "screen/matrix/types/point.h"
#include "screen/art/controls/menu/menuitem.h"

class Menu : public MenuItem {
    private:
        Point GetOffset() {
            Point offset = m_item.Position;

            if (m_item.Direction.X > 0)
                offset.X += m_items->size();
            else
                offset.Y += m_items->size();

            return offset;
        }

    public:
        Menu* Expand() {
            MenuItem::Expand();
            return this;
        }

        Menu* SetDirection(bool vertical) {
            MenuItem::SetDirection(vertical);
            return this;
        }

        Menu* SetItems() {
            MenuItem::SetItems();
            return this;
        }

        Menu* SetExit() {
            MenuItem::SetExit();
            return this;
        }

        Menu* Add(MenuItem* item) {
            MenuItem::Add(item);
            return this;
        }
};

#endif
