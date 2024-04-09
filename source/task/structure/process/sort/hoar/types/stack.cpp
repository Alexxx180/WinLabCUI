#include "task/structure/process/sort/hoar/types/stack.h"

HoarStack(long size) {
    Position = 1;
    SetBound(Left, 0);
    SetBound(Right, size - 1);
}

long HoarStack :: PivotIndex() { return (part.X + part.Y) >> 1; }
bool HoarStack :: IsSmallerOneLeft() { return part.X < part.Y; }
bool HoarStack :: HasQueries() { return Position != 0; }

void HoarStack :: UpdateBounds() {
    part.X = Left[Position];
    part.Y = Right[Position];
    Position--;
}

void HoarStack :: SetBound(long* boundary, long current) {
    boundary[Position] = current;
}

void HoarStack :: BoundCheck(long* axis, long* b1, long* b2, Vector2l* wall) {
    if (wall->X > *axis) {
        Position++;
        SetBound(b1, wall->X);
        SetBound(b2, *axis);
    }
    *axis = wall->Y;
}

void HoarStack :: LeftBound(Vector2l wall) {
    BoundCheck(&part.X, Right, Left, &wall);
}

void HoarStack :: RightBound(Vector2l wall) {
    BoundCheck(&part.Y, Left, Right, &wall);
}
