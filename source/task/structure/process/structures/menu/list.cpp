#include "task/structure/process/structures/list.h"
#include "task/structure/process/structures/menu/list.h"

List model;

void Random() { model.Randomized(); }

void Order() { model.Ordered(); }

char Search() { return model.Search(model.Input()); }

void JumpToSearch() { model.ToIndex(Search()); }

void Medium() {
    if (model.IsEmpty()) {
        out->Flip(1)->Move()->Text(model.Medium());
        Next();
        out->Clear()->Flip(-1)->Move();
    }
}

void InsertFirst() {
    if (model.HasSpace()) {
        model.Insert(0, model.Random());
        model.Show();
    }
}

void InsertLast() {
    if (model.HasSpace()) {
        model.Append(model.Random());
        model.Show();
    }
}

void InsertTo(char offset) {
    if (!model.HasSpace()) return;

    char position = Search();
    if (position != UNDEFINED) {
        char value = model.Random();
        char next = position + offset;
        if (offset < 0)
            next = next < 0 ? position : next;
            model.InsertTo(next, value);
        else if (next < model.size)
            model.InsertTo(next, value);
        else
            model.Append(value);
        model.Show();
    }
}

void InsertBefore() { InsertTo(-1); }
void InsertAfter() { InsertTo(1); }

void Remove(char index) {
    if (index != UNDEFINED) {
        model.Remove(index);
        model.Show();
    }
}

void RemoveAt() { if (!model.IsEmpty()) Remove(Search()); }

void RemoveFirst() { if (!model.IsEmpty()) Remove(0); }

void RemoveLast() { if (!model.IsEmpty()) Remove(model.size - 1); }

void Reset() {
    model.Reset();
    model.Show();
}
