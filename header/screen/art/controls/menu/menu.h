#ifndef SCREEN_ART_CONTROLS_MENU_MENU
#define SCREEN_ART_CONTROLS_MENU_MENU

#include <vector>
#include "screen/matrix/types/point.h"
#include "screen/art/controls/menu/menuitem.h"

class Menu : public MenuItem {
    private:
        void ApplyOffset(unsigned char offset) {
            if (m_item.Direction.X > 0)
                m_item.Position.X += offset;
            else
                m_item.Position.Y += offset;
        }

    public:
        Menu* Expand() {
			DrawItems();
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
            m_items->push_back(*item);
            m_limits.end = m_items->size() - 1;
            return this;
        }

		void Index(Point position) {
			SetPosition(&position);
			m_item.Index = 0;

			if (m_items == NULL) return;

			for (unsigned char i = 0; i < m_items->size(); i++) {
	            at(i).Index(position);
				ApplyDirection(&position);
			}
		}
};

#endif
