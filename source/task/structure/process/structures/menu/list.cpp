#include "task/structure/process/structures/list.h"
#include "task/structure/process/structures/menu/list.h"
#include "screen/matrix/tools.h"
#include "common/codes.h"

List model;

void ListRandomized() { model.Randomized(); }

void ListOrder() { model.Ordered(); }

char ListSearch() { return model.Search(model.Input()); }

void ListJumpToSearch() { model.ToIndex(ListSearch()); }

void ListMedium() {
    if (model.IsEmpty()) {
        out->Flip(1)->Move()->Text(model.Medium());
        Next();
        out->Clear()->Flip(-1)->Move();
    }
}

void ListInsertFirst() {
    if (model.HasSpace()) {
        model.Insert(0, model.Random());
        model.Show();
    }
}

void ListInsertLast() {
    if (model.HasSpace()) {
        model.Append(model.Random());
        model.Show();
    }
}

void ListInsertTo(char offset) {
    if (!model.HasSpace()) return;

    char position = ListSearch();
    if (position != UNDEFINED) {
        char value = model.Random();
        char next = position + offset;
        if (offset < 0) {
            next = next < 0 ? position : next;
            model.InsertTo(next, value);
        } else if (next < model.size) {
            model.InsertTo(next, value);
        } else {
            model.Append(value);
        }
        model.Show();
    }
}

void ListInsertBefore() { ListInsertTo(-1); }
void ListInsertAfter() { ListInsertTo(1); }

void ListRemove(char index) {
    if (index != UNDEFINED) {
        model.Remove(index);
        model.Show();
    }
}

void ListRemoveAt() { if (!model.IsEmpty()) ListRemove(ListSearch()); }

void ListRemoveFirst() { if (!model.IsEmpty()) ListRemove(0); }

void ListRemoveLast() { if (!model.IsEmpty()) ListRemove(model.size - 1); }

void ListReset() {
    model.Reset();
    model.Show();
}
