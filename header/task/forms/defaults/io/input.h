#include "input/prompt/string.h"
#include "input/prompt/numeric/verifier.h"
#include "input/prompt/numeric/randomizer.h"

void SetInputVerifiers();

extern Boundary<char> limits;
extern StringPrompt* prompts;
extern Verifier<char>* numeric;
extern Randomizer<char> gen_int8;
