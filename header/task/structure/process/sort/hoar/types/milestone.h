#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_MILESTONE
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_MILESTONE

#include <vector>

class HoarMilestone {
    private:
        int m_middle;

        bool HasDistance();
        void Divide(const std::vector<short>& memory);
        void Equalization(const std::vector<short>& memory);
        void Swap(const std::vector<short>& memory);

    public:
        int Left, Right;

        HoarMilestone(int first, int last);
        void Sort(const std::vector<short>& memory);
};

#endif
