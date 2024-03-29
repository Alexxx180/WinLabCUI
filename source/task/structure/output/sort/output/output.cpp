#include "task/structure/output/sort/output/output.h"

#include "task/structure/output/sort/output/show.h"
#include "task/structure/output/sort/output/restore.h"
#include "task/structure/output/sort/output/view/records.h"
#include "task/structure/output/sort/output/view/table.h"

void SortOutput() {
    ShowSorting();
    SortTable(&SortRecords());
    RestoreOutput();
}
