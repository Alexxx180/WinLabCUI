#include "task/structure/process/sort/hoar/types/milestone.h"

#include "task/structure/process/sort/utils/efficiency.h"

HoarMilestone :: HoarMilestone(int first, int last) {
    ResetStats();
    Left = first;
    Right = last;
}

bool HoarMilestone :: HasDistance() { return Comparison(Left <= Right); }

void HoarMilestone :: Divide(const std::vector<short>& memory) {
    Middle = memory[(Left + Right) / 2];
}

void HoarMilestone :: Swap(const std::vector<short>& memory) {
    if (Comparison(memory[Left] > memory[Right])) {
        SwapMemory(memory, Left, Right);
        Permutation();
    }
}

void HoarMilestone :: Equalization(const std::vector<short>& memory) {
    while (Comparison(memory[Left] < m_middle)) Left++;
    while (Comparison(memory[Right] > m_middle)) Right--;
}

void HoarMilestone :: Sort(const std::vector<short>& memory) {
    Divide(memory);
    do {
        Equalization(memory);
        if (HasDistance()) {
            Swap(memory);
            Left++;
            Right--;
        }
    } while (HasDistance());
}
