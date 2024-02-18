#include <vector>

#include "screen/art/controls/data/types/table.h"

extern std::vector<short> original, sorted;

void OutputArrayRow(std::vector<short>& array, Table* table);
void OutputArray(Table* table);
