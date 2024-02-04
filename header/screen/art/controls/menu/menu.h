#define SCREEN_ART_CONTROLS_MENU
#define SCREEN_ART_CONTROLS_MENU

#include <vector>

#include "input/boundary.h"
#include "screen/matrix/types/point.h"
#include "screen/art/controls/menu/types/selector.h"

static std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

class Menu {
    private:
        Point GetOffset() {
            Point offset = m_item.Position;

            if (m_item.Direction.X > 0)
                offset.X += m_items.size();
            else
                offset.Y += m_items.size();

            return offset;
        }

    protected:
        Selector m_item;
        Boundary<short> limits(0, 0);

        void (*m_command)() = NULL;
        std::vector<MenuItem>* m_items = NULL;

        void Minimize() {
            short size = m_items.size();
            while (--size > 0) {
                m_items[size].Focus();
                m_items[size].Clear();
            }
        }

        void Expand() {
            short size = m_items.size();
            while (--size > 0) {
                m_items[size].Focus();
                m_items[size].Draw();
            }
            Await(m_items[m_selection].Query, ESC);
            Minimize();
        }

        void SetSelection(short next) {
            if (limits.Verify(next)) {
                m_item.Index = next; 
                m_items[next].Focus();
            }
        }

        void Next() { SetSelection(m_item.Index + 1); }

        void Previous() { SetSelection(m_item.Index - 1); }

        void ExitTheMenu() { m_item.Code = ESC; }

    public:
        MenuItem& at(short item) { return m_items.at(item); }
        MenuItem& operator[](short item) { return m_items[item]; }

        void SetPosition(Point* position) {
            m_item.Position = *position;
        }

        Menu* SetDirection(bool vertical) {
            m_item.Direction = vertical ? { 0, 1 } : { 1, 0 };
            return this;
        }

        Menu* SetItems() {
            m_command = Expand;
            m_items = new std::vector<MenuItem>();
            return this;
        }

        Menu* SetCommand(void (*command)()) {
            m_command = command;
            return this;
        }

        Menu* SetExit() {
            m_command = ExitTheMenu;
            return this;
        }

        Menu* Add(MenuItem* item) {
            Point offset = GetOffset();
            item.SetPosition(&offset);
            m_items->push_back(*item);
            limits.end = m_items.size() - 1;
            return this;
        }

        char Query() {
            m_item.Code = Select(menu_input_keys);

            switch (m_item.Code) {
                case ENTER: m_items[m_selection].command(); break;
                case KEY_UP:
                case KEY_LEFT:
                    Previous();
                    break;
                case KEY_DOWN:
                case KEY_RIGHT:
                    Next();
                    break;
                default:
                    break;
            }

            return m_item.Code;
        }
}

#endif
