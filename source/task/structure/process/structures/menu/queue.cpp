#include "task/structure/process/structures/queue.h"
#include "task/structure/process/structures/menu/queue.h"

Queue model;

void Randomized() { model.Randomized(); }

void FromTwo() { model.FromTwo(); }

char Search() { return model.Search(model.Input()); }

void JumpToSearch() { model.ToIndex(Search()); }

void Append() {
    if (model.HasSpace()) model.Append(model.Random());
}

void ToFirst() { model.ToFirst(); }
void ToLast() { model.ToLast(); }

void Remove() { if (!model.IsEmpty()) model.Remove(); }

void Reset() {
    model.Reset();
    model.Show();
}
