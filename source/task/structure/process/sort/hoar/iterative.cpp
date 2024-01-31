#include <vector>

#include "common/types.h"

#define MAXSTACK 512 // 2048 max stack size

void QuickSortIterative(std::vector<short> memory) {
    long i, j, middle, pivot;

    HoarStack stack;
    stack.Init(memory.size() - 1);
 
    do {
        stack.UpdateBounds();
 
        do {
            middle = PivotIndex();
            pivot = memory[middle];
            i = stack.part.X;
            j = stack.part.Y;

            while (memory[i] < pivot) i++;
            while (memory[j] > pivot) j--;

            for (;i <= j; i++, j--) {
                while (memory[i] < pivot) i++;
                while (memory[j] > pivot) j--;
 
                SwapMemory(memory, i, j);
            }

            if (i < middle)
                stack.RightBound(i, j);
            else
                stack.LeftBound(j, i);

        } while (stack.IsSmallerOneLeft());

    } while (stack.HasQueries());
}
