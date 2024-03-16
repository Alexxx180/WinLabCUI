#ifndef SCREEN_ART_CONTROLS_MENU_CONTENT_LABEL
#define SCREEN_ART_CONTROLS_MENU_CONTENT_LABEL

#include <string>

#include "screen/art/controls/menu/content/field.h"

class Label : public Field {
    private:
		std::string m_caption;

	protected:
		char Action() { return -1; }
		void Next() {}
		void Previous() {}

    public:
		Label(std::string caption) { m_caption = caption; }

		void Draw() { Pen::ink().Quote(m_caption); }

        short SelectedIndex() { return -1; }
};

#endif
