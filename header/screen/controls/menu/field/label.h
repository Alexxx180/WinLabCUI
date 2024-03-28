#ifndef SCREEN_CONTROLS_MENU_FIELD_LABEL
#define SCREEN_CONTROLS_MENU_FIELD_LABEL

#include <string>
#include "screen/interaction/navigation.h"

class Label : public Navigation {
    private:
        std::string m_caption;

    protected:
        char Input();

    public:
        Label(std::string caption);
        void Draw();
};

#endif
