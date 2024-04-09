#include "task/forms/defaults/io/io.h"

#include <fcntl.h>

#include "screen/drawing/platform.h"
#include "task/forms/defaults/io/std.h"

void SetInputOutput() {
    SwitchStd(_O_U16TEXT);
    SetPlatformOutput();
    SetPlatformShape(BLOCK);
}
