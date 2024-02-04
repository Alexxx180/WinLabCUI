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
long check;

std::vector<char> table_controls = {
    ESC, HOME, END, PAGE_UP, PAGE_DOWN
};

void OutputStatus() {
    Pen::ink().screen->Span(0)->Form(1)->Page(0)->Size(1)->Line(0);
    Pen::ink().Quote("status_exit_esc")->screen->Page(1);
    Pen::ink().Quote("status_page_home")->screen->Page(2);
    Pen::ink().Quote("status_page_up")->screen->Line();
    Pen::ink().Quote("status_page_down")->screen->Page(1);
    Pen::ink().Quote("status_page_end")->screen->Page(0)->Span(1);
}

void OutputArrayRow(std::vector<short>& array, Table* table) {
    const wchar_t* numbers = L"%4i";
    unsigned int index;
    short item;   

    while (table->Over && table->End) {
        index = table->GetLines()->Absolute;
        item = array.at(index);

        Pen::ink().FText(numbers, item);
        table->Iterate();
    }   
}

void OutputArray(Table* table) {
    Page backup = *(table->GetLines());

    Pen::ink().screen->Line(0);
    OutputArrayRow(original, table);

    table.SetLines(backup);

    Pen::ink().screen->Line(1);
    OutputArrayRow(sorted, table);
}

void PagesPrint() {
    const wchar_t* numbers = L"%4i";

    Pen::ink().screen->Page(1);

    OutputArray();

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

void Output() {
    result = arguments;

    Pen::ink().array->Rows.Set(1.0f / 4.0f);
    Pen::ink().array->Columns.Set(1.0f / 6.0f);
    Pen::ink().Show()->screen->Span(1);

    lines.Y = 0;
    records.X = original.size();
    root.Y = Pen::ink().back->Rows.Rib(0);
    records.Y = Pen::ink().back->Columns.Rib(1) / 4;

    root.X = records.X % records.Y;
    pages.Y = records.X / records.Y;

    if (root.X != 0) pages.Y += 1;

    pages.X = (pages.Y >= 1) ? 1 : 0;

    Pen::ink().Target(FOOT);
    OutputStatus();
    Pen::ink().Target(MAIN);
    PagesPrint();
}

