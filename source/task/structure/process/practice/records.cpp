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
};

void OutputRecord(const Record& r) {
    const wchar_t* no = L"%5i";
    out->FText(no, r.type);
    out->FText(no, r.demand);
    out->FText(no, r.proposal);
    out->FText(no, r.today);
    out->FText(no, r.yesterday);
    out->Line()->Move();
}

void DemandOverProposal(char day) {
    while (day < month) {
        if (model[day].IsDemandBigger())
            OutputRecord(model[day]);
        day += week;
    }
}

void ShowRecords() {
    char day = WeekOption();
    out->Target(MAIN)->Page(0)->Span(2);
    for (char i = 1; i < 5; i++)
        out->Line(i)->Move()->Clear()->Move();

    out->Line(0)->Move()->Clip("records_weekly")->Line()->Move();
    DemandOverProposal(day);
    out->Target(MENU)->Move();
}
