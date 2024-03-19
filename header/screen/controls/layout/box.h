#ifndef SCREEN_ART_CONTROLS_LAYOUT_BOX
#define SCREEN_ART_CONTROLS_LAYOUT_BOX

#include <vector>

#include "common/types.h"
#include "screen/art/drawing.h"
#include "screen/art/types/stapler.h"
#include "screen/matrix/types/point.h"
#include "screen/matrix/types/range.h"

class Box {
private:
    std::vector<byte> m_vertices;

    void Line(Point* cursor, void (*pins)(Point*, byte), wchar_t symbol);
    void Surround(Stapler* gun);

public:
    Edges line;
    Range bounds;

    const std::vector<byte>& Vertices();
    byte Count();
    byte Rib(const byte current);
    void Lines(Stapler* gun);
    Box* Split(const float proportion);
    Box* Set(const byte count);
};

#endif
