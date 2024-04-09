#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK 512

#include "common/types/vector.h"

struct HoarStack {
    Vector2l part;
    long Position;
    long Left[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];
    long Right[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];

    HoarStack();
    long PivotIndex();
    bool IsSmallerOneLeft();
    bool HasQueries();
    void SetBound(long* boundary, long current);
    void BoundCheck(long* axis, long* b1, long* b2, Vector2l* wall);
    void Init(long size);
    void UpdateBounds();
    void LeftBound(Vector2l wall);
    void RightBound(Vector2l wall);
};

#endif
