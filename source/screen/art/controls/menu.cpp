#include "screen/art/controls/menu/menu.h"

Menu* Menu :: Expand() {
	DrawItems();
    return this;
}

Menu* Menu :: SetDirection(bool vertical) {
    MenuItem::SetDirection(vertical);
    return this;
}

Menu* Menu :: SetItems() {
    MenuItem::SetItems();
    return this;
}

Menu* Menu :: SetExit() {
    MenuItem::SetExit();
    return this;
}

Menu* Menu :: Add(MenuItem* item) {
	MenuItem::Add(item);
    return this;
}

void Menu :: Index(Point position) {
	SetPosition(&position);
	m_item.Index = 0;

	if (m_items == NULL) return;

	for (unsigned char i = 0; i < m_items->size(); i++) {
	    at(i).Index(position);
		ApplyDirection(&position);
	}
}
