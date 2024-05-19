#include "task/structure/process/structures/stack.h"
#include "task/structure/process/structures/menu/stack.h"
#include "task/forms/defaults/cui/screens/templates/stack.h"

Stack model;

void StackRandomized() { 
    StackInfo();
    model.Randomized();
    model.Show();
}

void StackMinimal() {
    if (!model.IsEmpty())
        model.ToIndex(model.Minimal());
}

char StackSearch() { return model.Search(model.Input()); }

void StackJumpToSearch() { model.ToIndex(StackSearch()); }

void StackAppend() {
    if (model.HasSpace()) {
        model.Append(model.Random());
        model.Show();
    }
}

void StackToLast() { model.ToLast(); }

void StackRemove() {
    if (!model.IsEmpty()) {
        model.Remove();
        model.Show();
    }
}

void StackReset() {
    model.Reset();
    model.Show();
}
