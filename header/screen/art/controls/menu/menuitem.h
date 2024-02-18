#ifndef SCREEN_ART_CONTROLS_MENU_MENUITEM
#define SCREEN_ART_CONTROLS_MENU_MENUITEM

#include <string>

#include "input/boundary.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/interaction.h"
#include "screen/art/controls/menu/option.h"
#include "screen/art/controls/menu/navigation.h"
#include "screen/art/controls/menu/types/selector.h"

class MenuItem : public Navigation {
    private:
        std::string m_caption;
        Option* m_values = NULL;
        void (*m_command)() = NULL;
        void (MenuItem::*m_internal)() = NULL;

        Point GetOffset() {
            Point offset = m_item.Position;
            offset.X += m_item.Direction.X;
            offset.Y += m_item.Direction.Y;
            offset.Y += m_items->size();
            return offset;
        }

        void ValueSelection() {
            char (Option::*query)() = &Option::Query;
            Await(m_values, query, ESC);
        }

    protected:
        std::vector<MenuItem>* m_items = NULL;
        Selector m_item;
        Boundary<short> m_limits = { 0, 0 };

        void Minimize() {
            short size = m_items->size();
            while (--size > 0)
                at(size).Focus()->Clear();
        }

        void Expand() {
            short size = m_items->size();
            while (--size > 0)
                at(size).Focus()->Draw();

            char (MenuItem::*query)() = &MenuItem::Query;
            MenuItem current = at(m_item.Index);

            Await(&current, query, ESC);
            Minimize();
            Focus();
        }

        void SetSelection(short next) {
            if (m_limits.Verify(next)) {
                m_item.Index = next; 
                at(next).Focus();
            }
        }

        void Next() { SetSelection(m_item.Index + 1); }

        void Previous() { SetSelection(m_item.Index - 1); }

        void Action() { at(m_item.Index).Command(); }

        void ExitTheMenu() { m_item.Code = ESC; }

    public:
        MenuItem& at(short item) { return m_items->at(item); }
        MenuItem& operator[](short item) { return at(item); }

        short GetValue() {
            return m_values->SelectedIndex();
        }

        void Command() {
            if (m_command != NULL)
                m_command();
            else
                ((this)->*(m_internal))();
        }

        void SetPosition(Point* position) {
            m_item.Position = *position;
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
            Point offset = GetOffset();

            item->SetPosition(&offset);
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
