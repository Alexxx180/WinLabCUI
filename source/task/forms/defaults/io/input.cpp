#include "task/forms/defaults/io/input.h"

#include "input/limiting/boundary.h"

void SetInputVerifiers() {
    numeric->status.Defaults();
}

Boundary<char> limits(-99, 99);
Verifier<char>* numeric = new Verifier<char>(limits);
Randomizer<char> gen_int8(limits);
