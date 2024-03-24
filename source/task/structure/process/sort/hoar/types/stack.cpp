#include "task/structure/process/sort/hoar/types/stack.h"

long HoarStack :: PivotIndex() { return (part.X + part.Y) >> 1; }
bool HoarStack :: IsSmallerOneLeft() { return part.X < part.Y; }
bool HoarStack :: HasQueries() { return Position != 0; }

void HoarStack :: Init(long size) {
    Position = 1;
    SetBounds({ 0, size - 1 });
}

void HoarStack :: UpdateBounds() {
    part.X = Left[Position];
    part.Y = Right[Position];
    Position--;
}

void HoarStack :: SetBounds(Point bounds) {
    Left[Position] = bounds.X;
    Right[Position] = bounds.Y;
}

void HoarStack :: SetBound(Liner liner, Vector2l* wall) {
    byte bound = liner.positions(&part);
    if (wall > bound) {
        Position++;
        Point bounds = { wall->X, wall->X };
        liner.shift(&bounds, bound);
        SetBounds(bounds);
    }
    liner.shift(&part, wall->Y);
}

void HoarStack :: LeftBound(Vector2l wall) {
    SetBound({ HPoint, HLine }, &wall);
}

void HoarStack :: RightBound(Vector2l wall) {
    SetBound({ VPoint, VLine }, &wall);
}
