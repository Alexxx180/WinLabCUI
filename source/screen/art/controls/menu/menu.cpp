#include "screen/art/controls/menu/menu.h"

Menu* Menu :: Expand() {
	DrawItems();
    return this;
}

Menu* Menu :: Vertical(bool direction) {
    MenuItem::Vertical(direction);
    return this;
}

Menu* Menu :: SetItems() {
    m_items = new std::vector<MenuItem>();
    m_internal = &MenuItem::Expand;
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
