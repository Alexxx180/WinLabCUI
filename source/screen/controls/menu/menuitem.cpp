#include "screen/controls/menu/menuitem.h"
#include "screen/interaction/controller/groups/menu.h"
#include "screen/interaction/controller/keyboard.h"
#include "screen/interaction/lifetime/internal.h"

void MenuItem :: InnerField(Navigation* parameters, char (MenuItem::*command)()) {
    m_internal = command;
    m_caption = parameters;
}

char MenuItem :: ValueSelection() {
    char (Navigation::*query)() = &Navigation::Query;
    Await(m_caption, query, ESC);
    Focus();
    return ENTER;
}

void MenuItem :: Minimize() {
    short size = m_items->size();
    while (--size >= 0) {
        MenuItem& item = at(size);
        Point pos = item.GetPos();
        item.Focus();
        item.Clear();
    }
}

void MenuItem :: DrawItems() {
    short size = m_items->size();
    while(--size >= 0)
        at(size).Focus()->Draw();
    at(0).Focus();
}

char MenuItem :: Expand() {
    DrawItems();
    char (MenuItem::*query)() = &MenuItem::Query;
    Await(this, query, ESC);
    Minimize();
    Focus();
    return ENTER;
}

void MenuItem :: SetSelection(short next) {
    if (!m_limits.Deny(next)) {
        m_item.Index = next; 
        at(next).Focus();
    }
}

void MenuItem :: Climb() {}
void MenuItem :: Slide() {}

void MenuItem :: First() {
    SetSelection(m_limits.start);
}

void MenuItem :: Last() {
    SetSelection(m_limits.end);
}

void MenuItem :: Next() {
    SetSelection(m_item.Index + 1);
}

void MenuItem :: Previous() {
    SetSelection(m_item.Index - 1);
}

char MenuItem :: Action() {
    return at(m_item.Index).Command();
}

char MenuItem :: ExitTheMenu() {
    return ESC;
}

Point MenuItem :: GetPos() {
    return m_item.Position;
}

MenuItem& MenuItem :: at(short item) {
    return m_items->at(item);
}

short MenuItem :: Choice() {
    return m_caption->Choice();
}

char MenuItem :: Command() {
    char code;
    if (m_command != NULL) {
        m_command();
        code = ENTER;
    } else {
        code = ((this)->*(m_internal))();
    }
    return code;
}

void MenuItem :: SetPosition(Point* position) {
    m_item.Position = *position;
}

void MenuItem :: ApplyDirection(Point* position) {
    position->X += m_item.Direction.X;
    position->Y += m_item.Direction.Y;
}

void MenuItem :: Index(Point position) {
    SetPosition(&position);
    ApplyDirection(&position);
    m_item.Index = 0;

    if (m_items == NULL) return;

    for (unsigned char i = 0; i < m_items->size(); i++) {
        at(i).Index(position);
        position.Y += 2;
    }
}

MenuItem* MenuItem :: Vertical(bool direction) {
    if (direction)
        m_item.Direction = { 0, 2 };
    else
        m_item.Direction = { 1, 0 };
    return this;
}

MenuItem* MenuItem :: SetItems(Label* caption) {
    m_items = new std::vector<MenuItem>();
    InnerField(caption, &MenuItem::Expand);
    return this;
}

MenuItem* MenuItem :: SetCommand(Label* caption, void (*command)()) {
    InnerField(caption, NULL);
    m_command = command;
    return this;
}

MenuItem* MenuItem :: SetExit(Label* caption) {
    InnerField(caption, &MenuItem::ExitTheMenu);
    return this;
}

MenuItem* MenuItem :: Add(MenuItem* item) {
    m_items->push_back(*item);
    m_limits.end = m_items->size() - 1;
    return this;
}

MenuItem* MenuItem :: SetField(Navigation* parameters) {
    InnerField(parameters, &MenuItem::ValueSelection);
    return this;
}

void MenuItem :: Draw() {
    m_caption->Draw();
}

MenuItem* MenuItem :: Clear() {
    out->Clear()->Move();
    return this;
}

MenuItem* MenuItem :: Focus() {
    Point pos = m_item.Position;
    out->Page(pos.X);
    out->Line(pos.Y);
    out->Move();
    return this;
}

char MenuItem :: Input() {
    return Select(menu_input.controls);
}
