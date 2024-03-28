#include "task/forms/defaults/io/input.h"

void SetInputVerifiers() {
    numeric->status.Defaults();
}

Verifier<char>* numeric = new Verifier<char>();
