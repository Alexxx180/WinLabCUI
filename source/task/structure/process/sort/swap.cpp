#include "task/structure/process/sort/swap.h"

#include <vector>

#include "common/types/vector.h"

Vector2s efficiency;

void Permutation() { efficiency.Y++; }

bool Comparison(bool condition) {
    efficiency.X++;
    return condition;
}

void SwapMemory(std::vector<short>& memory, int p1, int p2) {
    short placeholder = memory[p1];
    memory[p1] = memory[p2];
    memory[p2] = placeholder;
    Permutation();
}
