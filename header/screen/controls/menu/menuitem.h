#ifndef SCREEN_CONTROLS_MENU_MENUITEM
#define SCREEN_CONTROLS_MENU_MENUITEM

#include <string>
#include <memory>

#include "input/feedback/limiting/boundary.h"
#include "screen/matrix/tools.h"
#include "screen/matrix/types/point.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/navigation.h"
#include "screen/controls/menu/field/option.h"
#include "screen/controls/menu/field/label.h"
#include "screen/controls/menu/types/selector.h"

class MenuItem : public Navigation {
    private:
        Navigation* m_caption = NULL;
        void (*m_command)() = NULL;

        char ValueSelection();
        void InnerField(Navigation* parameters, char (MenuItem::*command)());

    protected:
        char (MenuItem::*m_internal)() = NULL;
        Selector m_item;
        std::vector<MenuItem>* m_items = NULL;
        Boundary<short> m_limits = { 0, 0 };

        void Minimize();
        void DrawItems();
        void SetSelection(short next);
        void Climb();
        void Slide();
        void First();
        void Last();
        void Next();
        void Previous();
        char Action();
        char ExitTheMenu();
        char Input();

    public:
        Point GetPos();
        MenuItem& at(short item);
        char Expand();
        char Command();
        void SetPosition(Point* position);
        void ApplyDirection(Point* position);
        void Index(Point position);
        MenuItem* Vertical(bool direction);
        MenuItem* SetCommand(Label* caption, void (*command)());
        MenuItem* SetItems(Label* caption);
        MenuItem* SetExit(Label* caption);
        MenuItem* Add(MenuItem* item);
        MenuItem* SetField(Navigation* parameters);
        short Choice();
        void Draw();
        MenuItem* Clear();
        MenuItem* Focus();
};

#endif
