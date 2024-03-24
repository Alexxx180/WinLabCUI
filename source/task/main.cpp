#include "task/main.h"

#include "task/forms/themes.h"
#include "task/forms/defaults.h"
#include "task/structure/input/tasks.h"
#include "common/codes.h"

int main(int argc, char** argv) {
    SetDefaults(argc, argv);

    char code = Header();
    if (code == ENTER) Input();
    code = Footer();

    return OK;
}
