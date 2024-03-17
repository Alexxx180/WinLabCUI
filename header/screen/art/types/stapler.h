#ifndef SCREEN_ART_TYPES_STAPLER
#define SCREEN_ART_TYPES_STAPLER

struct Stapler {
    void (*progress)(Point*, byte);
    void (*pins)(Point*, byte);

    void Set(void (*line)(Point*, byte),
            void (*points)(Point*, byte)) {
        progress = line;
        pins = points;
    }
};

#endif
