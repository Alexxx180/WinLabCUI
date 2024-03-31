#include "screen/controls/layout/grid/datagrid/types/scroll.h"

#include "screen/controls/matrix/pen.h"
#include "task/forms/defaults/debug.h"

void Scroll :: Home() { Current = Top; }

void Scroll :: End() { Current = Bottom; }

void Scroll :: Length() {
    Pen::ink().Text(Current, L" / ", Bottom);
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
