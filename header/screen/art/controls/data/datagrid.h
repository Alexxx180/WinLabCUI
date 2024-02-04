#ifndef SCREEN_ART_CONTROLS_

static std::vector<char> table_controls = {
    ESC, HOME, END, PAGE_UP, PAGE_DOWN
};

class DataGrid {
    private:
        void (*m_update)(Table *grid) = NULL;

    public:
        void OutputControls() {
            Pen::ink().screen->Span(0)->Form(1);
            Pen::ink().screen->Page(0)->Size(1)->Line(0);
            Pen::ink().Quote("status_exit_esc")->screen->Page(1);
            Pen::ink().Quote("status_page_home")->screen->Page(2);
            Pen::ink().Quote("status_page_up")->screen->Line();
            Pen::ink().Quote("status_page_down")->screen->Page(1);
            Pen::ink().Quote("status_page_end")->screen->Page(0);
            Pen::ink().screen->Span(1);
        }

void OutputArray(Table* table) {
    const wchar_t* numbers = L"%4i";
    short item, x, y;
    bool end, over;

    x = lines.X, y = lines.Y;
    end = x < records.Y;
    over = y < records.X;

    Pen::ink().screen->Line(0);
    while (over && end) {
        item = original.at(y);
        Pen::ink().FText(numbers, item);

        end = ++x < records.Y;
        over = ++y < records.X;
    }

    x = lines.X, y = lines.Y;
    end = x < records.Y;
    over = y < records.X;

    Pen::ink().screen->Line(1);
    while (over && end) {
        item = sorted.at(y);
        Pen::ink().FText(numbers, item);

        end = ++x < records.Y;
        over = ++y < records.X;
    }

    lines.X = x;
    lines.Y = y;
}

    void PagesPrint() {
        m_update(&table);

        Pen::ink().Target(FOOT)->screen->Move()->Clear()->Move();

        if (page_character_results)
            Pen::ink().Text(records.X, L" / ", lines.Y);
        else
            Pen::ink().Text(pages.Y, L" / ", pages.X, caption);

        Pen::ink().Target(MAIN);
    }

    void HomePage() {
        lines.Y = 0;
        pages.X = 1;
        PagesPrint();
    }

    void DownPage() {
        if (pages.X + page_listing > pages.Y) {
            HomePage();
            return;
        }

        pages.X += page_listing;

        check = lines.Y + records.Y * (page_listing - 1);

        lines.Y = (check > records.X) ? records.X - records.Y : check;

        PagesPrint();
    }

    void EndPage() {
        lines.Y = records.X - records.Y;
        pages.X = pages.Y;

        PagesPrint();
    }

    void UpPage() {
        if (pages.X - page_listing < 1) {
            EndPage();
            return;
        }
    
        pages.X -= page_listing;

        check = lines.Y - records.Y * (page_listing + 1);
    
        lines.Y = (check < 0) ? 0 : check;

    OutputArray();

        PagesPrint();
    }

    char Query() {
        char code = Select(table_controls);

        switch (code) {
            case HOME: HomePage(); break;
            case END: EndPage(); break;
            case PAGE_UP: UpPage(); break;
            case PAGE_DOWN: DownPage(); break;
            default: break;
        }

        return code;
    }

};
