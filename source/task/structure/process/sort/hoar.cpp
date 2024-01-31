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

//void

void QuickSortRecursive(std::vector<short>& memory, HoarSort* hoar) {
    int i = hoar->First, j = hoar->Last;
    int x = memory[(i + j) / 2];

    while (memory[i] < x) i++;
    while (memory[j] > x) j--;

    for (;i <= j; i++, j--) {
        while (memory[i] < x) i++;
        while (memory[j] > x) j--;
 
        NumericSwap(memory, i, j); //?
    }

    return 
 
    if (i < hoar.Last)
        QuickSortRecursive(memory, { i, hoar.Last });

    if (hoar.First < j)
        QuickSortRecursive(memory, { hoar.First, j });
} //0 / n - 1

HoarSort QuickSortIteration(std::vector<short>& memory, HoarSort* hoar) {
    int i = hoar.First, j = hoar.Last;
    int x = memory[(i + j) / 2];

    while (memory[i] < x) i++;
    while (memory[j] > x) j--;

    for (;i <= j; i++, j--) {
        while (memory[i] < x) i++;
        while (memory[j] > x) j--;
 
        NumericSwap(memory, i, j); //?
    }

    HoarSort current = { i, j };
    return 
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
