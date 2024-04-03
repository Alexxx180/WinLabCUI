#include "input/feedback/verifier.h"
#include "input/processing/randomizer.h"

void SetInputVerifiers();

extern Boundary<char> limits;
extern Verifier<char>* numeric;
extern Randomizer<char> gen_int8;
