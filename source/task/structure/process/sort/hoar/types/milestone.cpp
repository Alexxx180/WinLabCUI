#include "task/structure/process/sort/hoar/types/milestone.h"

#include "task/structure/process/sort/utils/efficiency.h"
#include "task/structure/process/sort/utils/swap.h"

HoarMilestone :: HoarMilestone(int first, int last) {
    ResetStats();
    Left = first;
    Right = last;
}

bool HoarMilestone :: HasDistance() { return Comparison(Left <= Right); }

void HoarMilestone :: Divide(const std::vector<short>& memory) {
    m_middle = memory[(Left + Right) / 2];
}

void HoarMilestone :: Swap(std::vector<short>& memory) {
    if (Comparison(memory[Left] > memory[Right])) {
        SwapMemory(memory, Left, Right);
        permutations++;
    }
}

void HoarMilestone :: Equalization(const std::vector<short>& memory) {
    while (Comparison(memory[Left] < m_middle)) Left++;
    while (Comparison(memory[Right] > m_middle)) Right--;
}

void HoarMilestone :: Sort(std::vector<short>& memory) {
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
