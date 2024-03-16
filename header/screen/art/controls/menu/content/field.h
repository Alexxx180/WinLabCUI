#ifndef SCREEN_ART_CONTROLS_MENU_CONTENT_FIELD
#define SCREEN_ART_CONTROLS_MENU_CONTENT_FIELD

#include "screen/art/controls/menu/navigation.h"

struct Field : public Navigation {
	virtual void Draw() = 0;
    virtual short SelectedIndex() = 0;
};

#endif
