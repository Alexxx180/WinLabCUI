#include "task/forms/defaults/io/input.h"

#include "input/limiting/boundary.h"

void SetInputVerifiers() {
    numeric->status.Defaults();
}

Verifier<char>* numeric = new Verifier<char>();
Randomizer<char> gen_int8(Boundary<char>(-99, 99));