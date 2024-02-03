#ifndef TASK_TYPES_HOAR
#define TASK_TYPES_HOAR 512

#include "common/types.h"

struct HoarStack {
    Vector2l part;
    long Position, Left[TASK_TYPES_HOAR], Right[TASK_TYPES_HOAR];

    long PivotIndex() { return (part.X + part.Y) >> 1; }
    bool IsSmallerOneLeft() { return part.X < part.Y; }
    bool HasQueries() { return Position != 0; }

    void Init(long size) {
        Position = 1;
        Left[Position] = 0;
        Right[Position] = size - 1;
    }
    
    void UpdateBounds() {
        part.X = Left[Position];
        part.Y = Right[Position];
        Position--;
    }

    void LeftBound(long wall, long iteration) {
        if (wall > part.X) {
            Position++;
            Left[Position] = part.X;
            Right[Position] = wall;
        }
        part.X = iteration;
    }

    void RightBound(long wall, long iteration) {
        if (wall > part.Y) {
            Position++;
            Left[Position] = wall;
            Right[Position] = part.Y;
        }
        part.Y = iteration;
    }

};

#endif
