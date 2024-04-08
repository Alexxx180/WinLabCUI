#include "task/structure/output/sort/output/clear.h"

#include "screen/matrix/tools.h"

void ClearStatus() {
    out->Target(FOOT);
    out->Move()->Clear()->Move();
    out->Target(MAIN);
}
