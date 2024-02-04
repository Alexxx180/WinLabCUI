#include <vector>

#include "common/types.h"

Vector2s efficiency;

void SwapMemory(std::vector<short>& memory, int p1, int p2) {
    short placeholder = memory[p1];
    memory[p1] = memory[p2];
    memory[p2] = placeholder;
}

void NumericSwap(std::vector<short>& memory, int p1, int p2) {
    efficiency.X++;

    if (memory[p1] > memory[p2]) {
        efficiency.Y++;
        SwapMemory(memory, p1, p2);
    }
}




void InsertionsSort(std::vector<short>& memory) {
    int i, j, size = memory.size();
    short floater;

    for (i = 1; i < size; i++) {
        floater = memory[i];
        j = i;
        while ((j-- >= 0) && (memory[j] < floater)) {
            memory[j + 1] = memory[j];
            memory[j] = floater;
        }
    }
}

void SelectionSort(std::vector<short>& memory) {
    int i, j, size = memory.size();

    for (i = 0; i < size - 1; i++) {
    /* устанавливаем начальное значение минимального индекса */
        int minimal = i;
	    /* находим индекс минимального элемента */
    	for (j = i + 1; j < size; j++) {

	    	if (memory[j] < memory[minimal])
		    	min_i = j;

    	}
	    /* меняем значения местами */
        SwapMemory(memory, i, minimal);
    }
}
