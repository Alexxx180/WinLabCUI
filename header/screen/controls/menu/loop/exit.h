#ifndef SCREEN_CONTROLS_MENU_LOOP_EXITMENU
#define SCREEN_CONTROLS_MENU_LOOP_EXITMENU

#include "screen/controls/menu/menu.h"

class ExitMenu {
    private:
        Menu m_options;

        char LiveLoop();

    public:
        void Set(Menu* options);
        void Capture();
};

#endif
