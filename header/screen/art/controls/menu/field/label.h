#ifndef SCREEN_ART_CONTROLS_MENU_CONTENT_LABEL
#define SCREEN_ART_CONTROLS_MENU_CONTENT_LABEL

#include <string>
#include "screen/interaction.h"
#include "screen/art/controls/menu/navigation.h"

class Label : public Navigation {
    private:
		std::string m_caption;

    public:
		Label(std::string caption);
		void Draw();
        char Query();
};

#endif
