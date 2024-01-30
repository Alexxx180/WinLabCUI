#include "task/structure/output.h"

#include <windows.h>

#include <vector>
#include <string>

#include "screen/art/controls/layers.h"
#include "screen/interaction.h"
#include "common/types.h"
#include "common/texts/common.h"
#include "output/format/pen.h"
#include "task/markdown/debug.h"

#include <conio.h>

Vector2i pages;
Vector2u lines, records, root;
std::vector<Answer> result;
long check;

std::vector<char> table_controls = {
    ESC, HOME, END, PAGE_UP, PAGE_DOWN
};

void OutputHeader() {
    Pen::ink().screen->Form(1)->Page(0)->Line(0)->Move();
    Pen::ink().Text(L"X")->screen->Page(2)->Move();
    Pen::ink().Text(L"Y")->screen->Page(4)->Move();
    Pen::ink().Text(L"Z");
    Pen::ink().screen->Size(2)->Line()->Size(1);
}

void OutputStatus() {
    Pen::ink().screen->Span(0)->Form(1)->Page(0)->Size(1)->Line(0);
    Pen::ink().Quote("status_exit_esc")->screen->Page(1);
    Pen::ink().Quote("status_page_home")->screen->Page(2);
    Pen::ink().Quote("status_page_up")->screen->Line();
    Pen::ink().Quote("status_page_down")->screen->Page(1);
    Pen::ink().Quote("status_page_end")->screen->Page(0)->Span(1);
}

void PagesPrint() {
    const wchar_t* numbers = L"%5.1f";
    float x, y;
    float* z;
    lines.X = 0;
    bool end = lines.X < records.Y;
    bool over = lines.Y < records.X;

    std::wstring caption = texts["status_pages"];
    Pen::ink().screen->Line(root.Y + 1);

    while (over && end) {
        x = result.at(lines.Y).X;
        y = result.at(lines.Y).Y;
        z = result.at(lines.Y).Z;

        Pen::ink().screen->Page(0)->Move()->Clear()->Move();
        Pen::ink().FText(numbers, x);
        Pen::ink().screen->Page(2)->Move()->Clear()->Move();
        Pen::ink().FText(numbers, y);
        Pen::ink().screen->Page(4)->Move()->Clear()->Move();

        if (z == NULL)
            Pen::ink().Text(L"---");
        else 
            Pen::ink().FText(L"%5.3f", *z);

        Pen::ink().screen->Line();

        end = ++lines.X < records.Y;
        over = ++lines.Y < records.X;
    }

    Pen::ink().Target(FOOT)->screen->Move()->Clear()->Move();

    if (page_character_results)
        Pen::ink().Text(records.X, L" / ", lines.Y);
    else
        Pen::ink().Text(pages.Y, L" / ", pages.X, caption);

    short thumb = (records.Y - 1) * pages.X / pages.Y;
    thumb += Pen::ink().back->Rows.Count() - 1 + root.Y;

    Pen::ink().Target(MAIN)->screen->Page(5)->Line(thumb)->Move();
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

    PagesPrint();
}

char OutputControl() {
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

void Output(std::vector<Answer> arguments) {
    result = arguments;

    short columns = 3;
    Pen::ink().back->Rows.Set(1.0f / 4.0f);
    Pen::ink().back->Columns.Set(columns);
    Pen::ink().Redraw()->screen->Span(1);

    lines.Y = 0;
    records.X = result.size();
    root.Y = Pen::ink().back->Rows.Rib(0);
    records.Y = Pen::ink().back->Rows.Rib(1);

    root.X = records.X % records.Y;
    pages.Y = records.X / records.Y;

    if (root.X != 0) pages.Y += 1;

    pages.X = (pages.Y >= 1) ? 1 : 0;

    OutputHeader();
    Pen::ink().Target(FOOT);
    OutputStatus();
    Pen::ink().Target(MAIN);
    PagesPrint();
}
