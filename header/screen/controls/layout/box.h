#ifndef SCREEN_CONTROLS_LAYOUT_BOX
#define SCREEN_CONTROLS_LAYOUT_BOX

#include <vector>

#include "common/types.h"
#include "screen/drawing/drawing.h"
#include "screen/drawing/types/constructs/outlines/edges.h"
#include "screen/matrix/change/stapler.h"
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
