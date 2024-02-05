#ifndef SCREEN_ART_TYPES_STAPLER
#define SCREEN_ART_TYPES_STAPLER

struct Stapler {
    void (*progress)(Point*, unsigned char);
    void (*pins)(Point*, unsigned char);

    void Set(
        void (*line)(Point*, unsigned char),
        void (*points)(Point*, unsigned char)
    ) {
        progress = line;
        pins = points;
    }
};

#endif
