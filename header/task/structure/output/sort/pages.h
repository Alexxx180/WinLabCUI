#include <vector>

#include "screen/controls/layout/grid/datagrid/types/table.h"

extern std::vector<short> original, sorted;

void DrawRow(std::vector<short>& array, Table* table);
void DrawArray(Table* table);
