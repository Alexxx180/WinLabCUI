#ifndef SCREEN_ART_CONTROLS_MENU_MENUITEM
#define SCREEN_ART_CONTROLS_MENU_MENUITEM

#include <string>
#include <memory>

#include "input/boundary.h"
#include "screen/matrix/pen.h"
#include "screen/matrix/types/point.h"
#include "screen/interaction.h"
#include "screen/art/controls/menu/content/field.h"
#include "screen/art/controls/menu/content/option.h"
#include "screen/art/controls/menu/content/label.h"
#include "screen/art/controls/menu/navigation.h"

class MenuItem : public Navigation {
    private:
		//std::shared_ptr<Field> m_caption(nullptr);
		Field* m_caption = NULL;
        void (*m_command)() = NULL;
        char (MenuItem::*m_internal)() = NULL;

        char ValueSelection();

    protected:
        Selector m_item;
        std::vector<MenuItem>* m_items = NULL;
        Boundary<short> m_limits = { 0, 0 };

        void Minimize();
		void DrawItems();
        char Expand();
        void SetSelection(short next);
        void Next();
        void Previous();
        char Action();
        char ExitTheMenu();

    public:
		Point GetPos();
        MenuItem& at(short item);
        short GetValue();
        char Command();
        void SetPosition(Point* position);
		void ApplyDirection(Point* position);
		void Index(Point position);
        MenuItem* SetDirection(bool vertical);
        MenuItem* SetCommand(void (*command)());
        MenuItem* SetExit();
        MenuItem* Add(MenuItem* item);
        MenuItem* SetCaption(std::unique_ptr<Label> caption);
        MenuItem* SetValues(std::unique_ptr<Option> parameters);
        void Choice();
        void Draw();
        MenuItem* Clear();
        MenuItem* Focus();
};

#endif
