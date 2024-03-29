#include "task/forms/defaults.h"

#include "task/forms/defaults/debug.h"
#include "task/forms/defaults/io/io.h"
#include "task/forms/defaults/cui/cui.h"

void SetDefaults(int argc, char** argv) {
    InitDbgVars(argc, argv);
    SetInputOutput();
    CharacterUserInterface();
}
