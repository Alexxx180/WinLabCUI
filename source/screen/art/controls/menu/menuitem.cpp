char MenuItem :: ValueSelection() {
    char (Field::*query)() = &Field::Query;
    Await(m_caption, query, ESC);
	wprintf(L"SELECTED");
	return ENTER;
}

void MenuItem :: Minimize() {
    short size = m_items->size();
    while (--size >= 0) {
		MenuItem& item = at(size);
		Point pos = item.GetPos();
		//wprintf(L"%i, ", size);
        //item.Focus();
		Pen::ink().screen->Page(pos.X);
	    Pen::ink().screen->Line(pos.Y);
		//Pen::ink().screen->Move(); // PROBLEM HERE
		wprintf(L"%i, %i", pos.X, pos.Y);
		//item.Clear();
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
	wprintf(L"S");
	return ENTER;
}

void SetSelection(short next) {
	//wprintf(L"%i", next);
    if (!m_limits.Verify(next)) {
		//wprintf(L"%i / %i", next, m_limits.end);
        m_item.Index = next; 
        at(next).Focus();
    }
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

Point MenItem :: GetPos() {
    return m_item.Position;
}

MenuItem& MenuItem :: at(short item) {
    return m_items->at(item);
}

short MenuItem :: GetValue() {
    return m_caption->SelectedIndex();
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
		position.Y += 1;
	}
}

MenuItem* MenuItem :: SetDirection(bool vertical) {
    if (vertical)
        m_item.Direction = { 0, 1 };
    else
        m_item.Direction = { 1, 0 };
    return this;
}

MenuItem* MenuItem :: SetItems() {
    m_internal = &MenuItem::Expand;
    m_items = new std::vector<MenuItem>();
    return this;
}

MenuItem* MenuItem :: SetCommand(void (*command)()) {
    m_command = command;
    return this;
}

MenuItem* MenuItem :: SetExit() {
    m_internal = &MenuItem::ExitTheMenu;
    return this;
}

MenuItem* MenuItem :: Add(MenuItem* item) {
    m_items->push_back(*item);
    m_limits.end = m_items->size() - 1;
    return this;
}

MenuItem* MenuItem :: SetCaption(std::unique_ptr<Label> caption) {
    m_caption = caption;
    return this;
}

MenuItem* MenuItem :: SetValues(std::unique_ptr<Option> parameters) {
    m_internal = &MenuItem::ValueSelection;
    m_caption = parameters;
    return this;
}

MenuItem* MenuItem :: Draw() {
	//Point pos = m_item.Position;
	//wprintf(L"D: %i, %i", pos.X, pos.Y);
	m_caption->Draw();
    return this;
}

MenuItem* MenuItem :: Clear() {
    Pen::ink().screen->Clear()->Move();
    return this;
}

MenuItem* MenuItem :: Focus() {
    Point pos = m_item.Position;
    Pen::ink().screen->Page(pos.X);
    Pen::ink().screen->Line(pos.Y);
    Pen::ink().screen->Move();
    return this;
}
