#include "task/structure/process/structures/queue.h"
#include "task/structure/process/structures/menu/queue.h"

Queue model;

void QueueRandomized() { model.Randomized(); }

void QueueFromTwo() { model.FromTwo(); }

char QueueSearch() { return model.Search(model.Input()); }

void QueueJumpToSearch() { model.ToIndex(QueueSearch()); }

void QueueAppend() {
    if (model.HasSpace()) model.Append(model.Random());
}

void QueueToFirst() { model.ToFirst(); }
void QueueToLast() { model.ToLast(); }

void QueueRemove() { if (!model.IsEmpty()) model.Remove(); }

void QueueReset() {
    model.Reset();
    model.Show();
}
