#include "screen/controls/bar/percentage/percents.h"

#include <string>

#include "screen/matrix/tools.h"

void Percents :: Calculate(float max) {
    Max = max;
    Count = static_cast<ushort>(Max * 10);

    std::string percentage = std::to_string(Count);
    Width = percentage.length() + 3;
}

void Percents :: Print(float basis) {
    pen->FText(Format, basis * Max);
}