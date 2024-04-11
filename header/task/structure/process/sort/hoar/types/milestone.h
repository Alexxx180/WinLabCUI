#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_MILESTONE
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_MILESTONE

#include <vector>

#include "task/structure/process/sort/utils/efficiency.h"
#include "task/structure/process/sort/utils/swap.h"

template<typename TYPE>
class HoarMilestone {
    private:
        TYPE m_middle;

        bool HasDistance() {
            return Comparison(Left <= Right);
        }

        void Divide(const std::vector<TYPE>& memory) {
            m_middle = memory[(Left + Right) / 2];
        }

        void Swap(std::vector<TYPE>& memory) {
            if (Comparison(memory[Left] > memory[Right])) {
                SwapMemory(memory, Left, Right);
                permutations++;
            }
        }

        void Equalization(const std::vector<TYPE>& memory) {
            while (Comparison(memory[Left] < m_middle)) Left++;
            while (Comparison(memory[Right] > m_middle)) Right--;
        }

    public:
        int Left, Right;

        HoarMilestone :: HoarMilestone(int first, int last) {
            ResetStats();
            Left = first;
            Right = last;
        }

        void Sort(std::vector<TYPE>& memory) {
            Divide(memory);
            do {
                Equalization(memory);
                if (HasDistance()) {
                    Swap(memory);
                    Left++; Right--;
                }
            } while (HasDistance());
        }
};

#endif
