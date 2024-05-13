#include "task/structure/process/practice/records/records.h"
#include "task/structure/input/menu.h"

const char week = 7;
const char month = 28;

Record model[28] = {
    { 0, 500, 400, 200,  120 }, { 1, 200,  20, 640, 5300 },
    { 2, 135, 420, 440,   23 }, { 0, 410, 123, 250,  350 },
    { 0, 556, 724, 856,  430 }, { 2, 760, 443, 240,  470 },
    { 3, 589, 670, 380, 2710 }, { 0, 513, 232, 901, 1923 },
    { 0,  23, 560, 889,   12 }, { 3, 612, 420, 440,  459 },
    { 2, 123, 784, 124, 9320 }, { 0, 548, 718, 293, 3280 },
    { 0, 663,  21,  41, 3481 }, { 2, 680, 281, 483,  565 },
    { 0, 391, 101, 231, 1923 }, { 1,  23, 122, 222,  384 },
    { 0, 291, 420, 999,  111 }, { 0, 132, 784, 894, 9320 },
    { 2, 289, 398, 679,  132 }, { 0, 593, 311, 442, 3231 },
    { 3, 132, 281,  83,  565 }, { 0, 100, 393, 231, 1342 },
    { 0, 124, 823, 222,  444 }, { 0,   5, 998, 233,  472 },
    { 1, 839, 784, 894,  239 }, { 0, 128, 398, 679,  132 },
    { 2, 302, 101, 442, 4891 }, { 0, 132, 281,  83,  543 }
}

std::vector<Record> DemandOverProposal(char day) {
    std::vector<Record> target;
    while (day < month) {
        if (model[day].IsDemandBigger())
            target.push_back(model[day]);
        day += week;
    }
    return target;
}

void ShowRecords() {
    char day = WeeklyOption();
    out->Target(MAIN)->Page(0)->Line(0);
    out->Clip("records_weekly");
    std::vector<Record> records = DemandOverProposal(day);
    for (char i = 0; i < month; i++) {
        const Record& r = records[i];
        out->Text(r.type, L" ", r.demand, L" ", r.proposal, L" ");
        out->Text(r.today, L" ", r.yesterday);
        out->Line();
    }
}
