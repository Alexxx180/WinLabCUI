#ifndef SCREEN_ART_CONTROLS_DATA_TYPES_SCROLL
#define SCREEN_ART_CONTROLS_DATA_TYPES_SCROLL

#include "task/forms/debug.h"
#include "screen/matrix/pen.h"

struct Scroll {
    const unsigned char Top = 1;

    int Current, Bottom;

    void Home() { Current = Top; }

    void End() { Current = Bottom; }

    void Length() {
        Pen::ink().Text(Current);
        Pen::ink().Text(L" / ");
        Pen::ink().Text(Bottom);
    }

    bool Down() {
        bool wall = Current + page_listing > Bottom;

        if (wall)
            Home();
        else
            Current += page_listing;

        return wall;
    }

    bool Up() {
        bool wall = Current - page_listing < Top;
        
        if (wall)
            End();
        else
            Current -= page_listing;
    
        return wall;
    }
};

#endif
