#ifndef SCREEN_ART_CONTROLS_MENU_NAVIGATION
#define SCREEN_ART_CONTROLS_MENU_NAVIGATION

#include <string>
#include <vector>

#include "screen/interaction.h"
#include "screen/art/controls/menu/types/selector.h"

static std::vector<char> menu_input_keys = {
    ESC, ENTER, KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT
};

class Navigation {
    protected:
        Selector m_item;
        virtual char Action() = 0;
        virtual void Previous() = 0;
        virtual void Next() = 0;

    public:
		void Navigate(char code) { m_item.Code = code; }

        char Query() {
            Navigate(Select(menu_input_keys));
			//wprintf(L"Code: %i", code);

            switch (m_item.Code) {
                case ENTER:
					//wprintf(L"B: %i", m_code);
                    m_item.Code = Action();
					//wprintf(L"A: %i", m_code);
                    break;
                case KEY_UP:
                case KEY_LEFT:
					//wprintf(L"LEFT");
                    Previous();
                    break;
                case KEY_DOWN:
                case KEY_RIGHT:
					//wprintf(L"RIGHT");
                    Next();
                    break;
                default:
                    break;
            }

            return m_item.Code;
        }
};

#endif
