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
        virtual char Action() = 0;
        virtual void Previous() = 0;
        virtual void Next() = 0;

    public:
        char Query() {
            char code = Select(menu_input_keys);
			//wprintf(L"Code: %i", code);

            switch (code) {
                case ENTER:
					//wprintf(L"B: %i", m_code);
                    code = Action();
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

            return code;
        }
};

#endif
