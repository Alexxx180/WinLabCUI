#include "task/structure/process/structures/queue.h"
#include "task/structure/process/structures/menu/queue.h"
#include "task/forms/defaults/cui/screens/templates/queue.h"

Queue model;

void QueueRandomized() {
    QueueInfo();
    model.Randomized();
    model.Show();
}

void QueueFromTwo() {
    QueueInfo();
    model.FromTwo();
    model.Show();
}

char QueueSearch() { return model.Search(model.Input()); }

void QueueJumpToSearch() { model.ToIndex(QueueSearch()); }

void QueueAppend() {
    if (model.HasSpace()) {
        model.Append(model.Random());
        model.Show();
    }
}

void QueueToFirst() { model.ToFirst(); }
void QueueToLast() { model.ToLast(); }

void QueueRemove() {
    if (!model.IsEmpty()) {
        model.Remove();
        model.Show();
    }
}

void QueueReset() {
    model.Reset();
    model.Show();
}
