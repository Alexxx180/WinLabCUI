#include <io.h>
#include <fcntl.h>

void SwitchStd(uint mode) {
    _setmode(_fileno(stdout), mode);
    _setmode(_fileno(stdin), mode);
    _setmode(_fileno(stderr), mode);
}
