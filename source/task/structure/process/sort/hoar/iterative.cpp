#include "task/structure/process/sort/hoar/iterative.h"

#include "task/structure/process/sort/hoar/types/stack.h"
#include "task/structure/process/sort/utils/swap.h"
#include "task/structure/process/sort/utils/efficiency.h"

void QuickSortIterative(std::vector<short>& memory) {
    ResetStats();

    long i, j, middle, pivot;

    HoarStack stack(memory.size() - 1);

    do {
        stack.UpdateBounds();

        do {
            middle = stack.PivotIndex();
            pivot = memory[middle];
            i = stack.part.X;
            j = stack.part.Y;

            while (Comparison(memory[i] < pivot)) i++;
            while (Comparison(memory[j] > pivot)) j--;

            for (;i <= j; i++, j--) {
                while (Comparison(memory[i] < pivot)) i++;
                while (Comparison(memory[j] > pivot)) j--;

                SwapMemory(memory, i, j);
                Permutation();
            }

            if (i < middle)
                stack.RightBound({ i, j });
            else
                stack.LeftBound({ j, i });

        } while (stack.IsSmallerOneLeft());

    } while (stack.HasQueries());
}
