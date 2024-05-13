#ifndef TASK_STRUCTURE_PROCESS_PRACTICE_RECORDS
#define TASK_STRUCTURE_PROCESS_PRACTICE_RECORDS

#include "task/structure/process/practice/records/record.h"
#include <vector>

class Records {
    private:
        const char week = 7;
        Record model[28];

    public:
        std::vector<Record> DemandOverProposal(char i);
        Records();
};

#endif
