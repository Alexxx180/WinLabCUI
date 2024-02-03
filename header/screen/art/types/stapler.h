#ifndef SCREEN_ART_TYPES_STAPLER
#define SCREEN_ART_TYPES_STAPLER

struct Stapler {
    void (*progress)(Point*, short);
    void (*pins)(Point*, short);

    void Set(
        void (*line)(Point*, short),
        void (*points)(Point*, short)
    ) {
        progress = line;
        pins = points;
    }
};

#endif
