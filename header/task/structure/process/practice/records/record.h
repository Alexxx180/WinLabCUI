#ifndef TASK_STRUCTURE_PROCESS_PRACTICE_RECORDS_RECORD
#define TASK_STRUCTURE_PROCESS_PRACTICE_RECORDS_RECORD

#include "common/types.h"

struct Record {
    byte type;
    unsigned short demand, proposal;
    unsigned short today, yesterday;

    bool IsDemandBigger() {
        return demand > proposal;
    }
};

#endif
