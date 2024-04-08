#include "task/structure/output/sort/output/output.h"

#include "task/structure/output/sort/output/view/records.h"
#include "task/structure/output/sort/output/view/table.h"

void SortOutput() {
    SortTable(SortRecords());
}
