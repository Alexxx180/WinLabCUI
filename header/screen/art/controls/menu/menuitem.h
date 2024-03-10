#ifndef SCREEN_ART_CONTROLS_MENU_MENUITEM
#define SCREEN_ART_CONTROLS_MENU_MENUITEM

#include <string>

#include "input/boundary.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/interaction.h"
#include "screen/art/controls/menu/option.h"
#include "screen/art/controls/menu/navigation.h"

class MenuItem : public Navigation {
    private:
        std::string m_caption;
        Option* m_values = NULL;
        void (*m_command)() = NULL;
        char (MenuItem::*m_internal)() = NULL;

        char ValueSelection() {
            char (Option::*query)() = &Option::Query;
            Await(m_values, query, ESC);
			return ENTER;
        }

    protected:
        std::vector<MenuItem>* m_items = NULL;
        Boundary<short> m_limits = { 0, 0 };

        void Minimize() {
            short size = m_items->size();
            while (--size >= 0)
                at(size).Focus()->Clear();
        }

		void DrawItems() {
            short size = m_items->size();
			while(--size >= 0)
                at(size).Focus()->Draw();
			at(0).Focus();
		}

        char Expand() {
			DrawItems();
            char (MenuItem::*query)() = &MenuItem::Query;

            Await(this, query, ESC);
            Minimize();
            Focus();
			return ENTER;
        }

        void SetSelection(short next) {
			//wprintf(L"%i", next);
            if (!m_limits.Verify(next)) {
				//wprintf(L"%i / %i", next, m_limits.end);
                m_item.Index = next; 
                at(next).Focus();
            }
        }

        void Next() { SetSelection(m_item.Index + 1); }

        void Previous() { SetSelection(m_item.Index - 1); }

        char Action() { return at(m_item.Index).Command(); }

        char ExitTheMenu() { return ESC; }

    public:
        MenuItem& at(short item) { return m_items->at(item); }
        MenuItem& operator[](short item) { return at(item); }

        short GetValue() { return m_values->SelectedIndex(); }

        char Command() {
			char code;
            if (m_command != NULL) {
                m_command();
				code = ENTER;
			} else {
                code = ((this)->*(m_internal))();
			}
			return code;
        }

        void SetPosition(Point* position) {
            m_item.Position = *position;
        }

		void ApplyDirection(Point* position) {
			position->X += m_item.Direction.X;
			position->Y += m_item.Direction.Y;
		}

		void Index(Point position) {
			SetPosition(&position);
			ApplyDirection(&position);
			m_item.Index = 0;

			if (m_items == NULL) return;

			for (unsigned char i = 0; i < m_items->size(); i++) {
	            at(i).Index(position);
				position.Y += 1;
			}
		}

        MenuItem* SetDirection(bool vertical) {
            if (vertical)
                m_item.Direction = { 0, 1 };
            else
                m_item.Direction = { 1, 0 };
            return this;
        }

        MenuItem* SetItems() {
            m_internal = &MenuItem::Expand;
            m_items = new std::vector<MenuItem>();
            return this;
        }

        MenuItem* SetCommand(void (*command)()) {
            m_command = command;
            return this;
        }

        MenuItem* SetExit() {
            m_internal = &MenuItem::ExitTheMenu;
            return this;
        }

        MenuItem* Add(MenuItem* item) {
            m_items->push_back(*item);
            m_limits.end = m_items->size() - 1;
            return this;
        }

        MenuItem* SetCaption(std::string caption) {
            m_caption = caption;
            return this;
        }

        MenuItem* SetValues(Option* parameters) {
            m_internal = &MenuItem::ValueSelection;

            m_values = parameters;
            m_values->BindCaption(&m_caption);
            return this;
        }

        MenuItem* Draw() {
			//Point pos = m_item.Position;
			//wprintf(L"D: %i, %i", pos.X, pos.Y);
			Pen::ink().Quote(m_caption);
            return this;
        }

        MenuItem* Clear() {
            Pen::ink().screen->Clear()->Move();
            return this;
        }

        MenuItem* Focus() {
            Point pos = m_item.Position;
            Pen::ink().screen->Page(pos.X);
            Pen::ink().screen->Line(pos.Y);
            Pen::ink().screen->Move();
            return this;
        }
};

#endif
