#define SCREEN_ART_CONTROLS_MENU
#define SCREEN_ART_CONTROLS_MENU

#include <string>

#include "screen/art/controls/menu/menu.h"
#include "screen/art/controls/menu/option.h"
#include "screen/matrix/types/point.h"

class MenuItem : public Menu {
    private:
        std::string m_caption;

        Point GetOffset() {
            Point offset = m_item.Position;
            offset.X += m_item.Direction.X;
            offset.Y += m_item.Direction.Y;
            offset.Y += m_items.size();
            return offset;
        }

    protected:
        void Expand() {
            Base::Expand();
            Focus();
        }

        void SelectValue() { Await(values.Select, ESC); }

    public:
        Option* values = NULL;

        MenuItem* SetOrientation(bool vertical) {
            Base::SetOrientation(vertical);
            return this;
        }

        MenuItem* SetItems() {
            Base::SetItems();
            return this;
        }

        MenuItem* SetCommand(void (*command)()) {
            Base::SetCommand(command);
            return this;
        }

        MenuItem* SetExit() {
            Base::SetExit();
            return this;
        }

        MenuItem* Add(MenuItem* item) {
            Base::Add(item);
            return this;
        }

        MenuItem* SetCaption(std::string caption) {
            m_caption = caption;
            return this;
        }

        MenuItem* SetValues(Option* parameters) {
            m_command = SelectValue;
            values = parameters;
            values->BindCaption(&m_caption);
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
}

#endif
