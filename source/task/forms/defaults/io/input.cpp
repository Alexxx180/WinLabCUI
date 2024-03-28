#include "input/feedback/verifier.h"

void SetInputVerifiers() {
    numeric->status.Defaults();
}

Verifier<char>* numeric = new Verifier<char>();
