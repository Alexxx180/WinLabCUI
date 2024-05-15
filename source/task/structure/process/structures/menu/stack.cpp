#include "task/structure/process/structures/stack.h"
#include "task/structure/process/structures/menu/stack.h"

Stack model;

void Random() { model.Randomized(); }

void Minimal() {
    if (!model.IsEmpty()) model.ToIndex(model.Minimal());
}

char Search() { return model.Search(model.Input()); }

void JumpToSearch() { model.ToIndex(Search()); }

void Append() {
    if (model.HasSpace()) model.Append(model.Random());
}

void ToLast() { model.ToLast(); }

void Remove() { if (!model.IsEmpty()) model.Remove(); }

void Reset() {
    model.Reset();
    model.Show();
}
