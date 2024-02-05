#include "task/structure/process/sort/hoar/iterative.h"

#include <vector>

#include "task/structure/process/sort/hoar/types/stack.h"

void QuickSortIterative(std::vector<short>& memory) {
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

            while (Comparison(memory[i] < pivot)) i++;
            while (Comparison(memory[j] > pivot)) j--;

            for (;i <= j; i++, j--) {
                while (Comparison(memory[i] < pivot)) i++;
                while (Comparison(memory[j] > pivot)) j--;
 
                SwapMemory(memory, i, j);
            }

            if (i < middle)
                stack.RightBound(i, j);
            else
                stack.LeftBound(j, i);

        } while (stack.IsSmallerOneLeft());

    } while (stack.HasQueries());
}
