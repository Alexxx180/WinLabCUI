#define SCREEN_ART_CONTROLS_MENU
#define SCREEN_ART_CONTROLS_MENU

#include <vector>
#include "screen/matrix/types/point.h"
#include "screen/art/controls/menu/menuitem.h"

class Menu : public MenuItem {
    private:
        Point GetOffset() {
            Point offset = m_item.Position;

            if (m_item.Direction.X > 0)
                offset.X += m_items.size();
            else
                offset.Y += m_items.size();

            return offset;
        }

    public:
        Menu* SetDirection(bool vertical) {
            Base::SetDirection(vertical);
            return this;
        }

        Menu* SetItems() {
            m_command = Expand;
            m_items = new std::vector<MenuItem>();
            return this;
        }

        Menu* SetExit() {
            Base::SetExit();
            return this;
        }

        Menu* Add(MenuItem* item) {
            Base::Add(item);
            return this;
        }
};

#endif
