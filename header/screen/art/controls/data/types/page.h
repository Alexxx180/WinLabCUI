#ifndef SCREEN_ART_CONTROLS_DATA_TYPES_PAGE
#define SCREEN_ART_CONTROLS_DATA_TYPES_PAGE

struct Page {
    unsigned char Relative;
    unsigned int Absolute;

    void Iterate() {
        Relative += page_listing;
        Absolute += page_listing;
    }
};

#endif
