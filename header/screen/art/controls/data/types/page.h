#ifndef SCREEN_ART_CONTROLS_DATA_TYPES_PAGE
#define SCREEN_ART_CONTROLS_DATA_TYPES_PAGE

#include "task/forms/debug.h"

class Page {
private:
    const unsigned char Top = 0;

public:
    unsigned char Relative;
    unsigned int Absolute;

    void Set(Page* page) {
        this->Relative = page->Relative;
        this->Absolute = page->Absolute;
    }

    void Iterate() {
        Relative += page_listing;
        Absolute += page_listing;
    }

    void Home() {
        Relative = Absolute = Top;
    }

    void End(unsigned int basis) {
        Relative = Top;
        Absolute = basis - Relative;
    }

    void Down(unsigned int wall, unsigned char lines) {
        short step = page_listing - 1;
        long check = Relative + lines * step;

        Relative = (check > wall) ? wall - lines : check;
    }

    void Up(unsigned char lines) {
        short step = page_listing + 1;
        long check = Relative - lines * step;

        Relative = (check < Top) ? Top : check;
    }

    int Split() {
        int start = Absolute % Relative;
        int end = Absolute / Relative;

        if (start != 0)
            end += 1;

        return end;
    }
};

#endif
