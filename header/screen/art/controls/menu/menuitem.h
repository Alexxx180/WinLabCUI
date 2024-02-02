#define SCREEN_ART_CONTROLS_MENU
#define SCREEN_ART_CONTROLS_MENU

#include <vector>

#include <windows.h>

#include "common/types.h"

class MenuItem {
    private:
        void (*m_command)() = NULL, (*m_back)() = NULL;
        std::vector<MenuItem>* m_items = NULL;
        Vector2c m_orientation, m_position;
        unsigned char m_selection;
        std::string m_caption;

        void SetSelection(short next) {
            m_selection = next;
            m_items[m_selection].Focus();
        }

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
            Await(m_items[0].Query, ESC);
            Minimize();
            Focus();
        }

        COORD GetOffset() {
            short size = m_items.size();
            COORD offset = {
                m_position.X + m_orientation.X,
                m_position.Y + m_orientation.Y + size
            };
            return offset
        }

        void Next() {
            short next = m_selection + 1;
            if (next < m_items.size())
                SetSelection(next);
        }

        void Previous() {
            short next = m_selection - 1;
            if (next > 0)
                SetSelection(next);
        }

        void SelectValue() {
            Await(values.Select, ESC);
        }

    public:
        Option* values = NULL;

        MenuItem& at(short item) { return m_items.at(item); }
        MenuItem& operator[](short item) { return m_items[item]; }

        void SetPosition(COORD* position) {
            m_position = *position;
        }

        MenuItem* SetItems() {
            m_command = Expand;
            m_items = new std::vector<MenuItem>();
            return this;
        }

        MenuItem* SetOrientation(bool vertical) {
            m_orientation = vertical ? { 0, 1 } : { 1, 0 };
            return this;
        }

        MenuItem* SetCommand(void (*command)()) {
            m_command = command;
            return this;
        }

        MenuItem* SetParameters(Option* parameters) {
            values = parameters;
            values->BindCaption(&m_caption);
            m_command = SelectValue;
            return this;
        }

        MenuItem* Add(MenuItem* item) {
            COORD offset = GetOffset;
            item.SetPosition(&offset);
            m_items->push_back(*item);
            return this;
        }

        void Draw() {
            Pen::ink().Quote(m_caption);
        }

        void Clear() {
            Pen::ink().screen->Clear()->Move();
        }

        void Focus() {
            Pen::ink().screen->Page(m_position.X);
            Pen::ink().screen->Line(m_position.Y);
            Pen::ink().screen->Move();
        }

        char Query() {
            char code = Select(menu_input_keys);

            switch (code) {
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

            return code;
        }
}

#endif
