#include "screen/controls/layout/grid/datagrid/types/page.h"
#include "task/forms/debug.h"

void Page :: Set(Page* page) {
    this->Relative = page->Relative;
    this->Absolute = page->Absolute;
}

void Page :: Iterate() {
    Relative += page_listing;
    Absolute += page_listing;
}

void Page :: Home() {
    Relative = Absolute = Top;
}

void Page :: End(uint basis) {
    Relative = Top;
    Absolute = basis - Relative;
}

void Page :: Down(uint wall, byte lines) {
    short step = page_listing - 1;
    long check = Relative + lines * step;

    Relative = (check > wall) ? wall - lines : check;
}

void Page :: Up(byte lines) {
    short step = page_listing + 1;
    long check = Relative - lines * step;

    Relative = (check < Top) ? Top : check;
}

int Page :: Split() {
    int start = Absolute % Relative;
    int end = Absolute / Relative;

    if (start != 0) end += 1;

    return end;
}
