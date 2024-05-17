#include "task/structure/process/structures/stack.h"
#include "task/structure/process/structures/menu/stack.h"

Stack model;

void StackRandomized() { model.Randomized(); }

void StackMinimal() {
    if (!model.IsEmpty()) model.ToIndex(model.Minimal());
}

char StackSearch() { return model.Search(model.Input()); }

void StackJumpToSearch() { model.ToIndex(StackSearch()); }

void StackAppend() {
    if (model.HasSpace()) model.Append(model.Random());
}

void StackToLast() { model.ToLast(); }

void StackRemove() { if (!model.IsEmpty()) model.Remove(); }

void StackReset() {
    model.Reset();
    model.Show();
}
