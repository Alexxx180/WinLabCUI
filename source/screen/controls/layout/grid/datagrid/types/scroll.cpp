#include "screen/controls/layout/grid/datagrid/types/scroll.h"
#include "task/forms/debug.h"
#include "screen/matrix/pen.h"

void Scroll :: Home() { Current = Top; }

void Scroll :: End() { Current = Bottom; }

void Scroll :: Length() {
    Pen::ink().Text(Current);
    Pen::ink().Text(L" / ");
    Pen::ink().Text(Bottom);
}

bool Scroll :: Down() {
    bool wall = Current + page_listing > Bottom;

    if (wall) Home(); else Current += page_listing;

    return wall;
}

bool Scroll :: Up() {
    bool wall = Current - page_listing < Top;
        
    if (wall) End(); else Current -= page_listing;
    
    return wall;
}
