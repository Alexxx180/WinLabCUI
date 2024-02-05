#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK
#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK 512

#include "common/types.h"

struct HoarStack {
    Vector2l part;
    long Position;
    long Left[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];
    long Right[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];

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
