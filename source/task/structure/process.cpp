#include "task/structure/process.h"

#include <math.h>

#include <vector>

#include "common/types.h"
#include "screen/interaction.h"
#include "output/format/pen.h"

#include <conio.h>

void Determine(Answer* result) {
    float x = result->X, y = result->Y;

    float z1 = pow(x, 3) + 3 * y;
    if (z1 <= 0.0f) return;

    float z2 = exp(x) + 2.0f * sinf(y);
    if (z2 == 0.0f) return;

    z1 = 3.5f * logf(z1);

    result->Set(z1 / z2);
}

std::vector<Answer> Process(Loop2* laps) {
    float x, y;
    unsigned int i = 0, count = laps->count;

    Pen::ink().status.SetDivisions(count)->Show();
    std::vector<Answer> result(count);

    x = laps->X.start;

    while (x <= laps->X.end && i < count) {

        y = laps->Y.start;

        while (y <= laps->Y.end && i < count) {

            result[i].Input(x, y);
            result[i].Z = NULL;
            Determine(&result[i]);
            Pen::ink().status.ProgressData(++i);
            y += laps->Y.step;

        }

        x += laps->X.step;
    }

    return result;
}
