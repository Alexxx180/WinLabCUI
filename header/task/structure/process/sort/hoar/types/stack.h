#ifndef TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK
#define TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK 512

struct HoarStack {
    long Index;
    long Stack[TASK_STRUCTURE_PROCESS_SORT_HOAR_TYPES_STACK];

    void Update(long position);
};

#endif
