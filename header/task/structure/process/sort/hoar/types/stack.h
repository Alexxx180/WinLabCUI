#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK 512

#include "common/types/vector.h"
#include "screen/matrix/change/liner.h"

struct HoarStack {
    Vector2l part;
    long Position;
    long Left[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];
    long Right[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];

    long PivotIndex();
    bool IsSmallerOneLeft();
    bool HasQueries();
    void SetBounds(Point bounds);
    void SetBound(Liner liner, Vector2l* wall);
    void Init(long size);
    void UpdateBounds();
    void LeftBound(Vector2l wall);
    void RightBound(Vector2l wall);
};

#endif
