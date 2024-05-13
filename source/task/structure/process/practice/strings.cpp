#include "task/structure/process/practice/strings.h"

const std::wstring text = L"Example of (original) string";

std::wstring Replace() {
    size_t start = text.find(L"(");
    size_t end = text.find(L")");
    return text.replace(start, end - start, L"");
}

std::wstring[2] RandomSortedWords() {
    Boundary<char> latin(97, 25);
    Boundary<char> count(1, 8);
    char i = 2;

    std::wstring words[2] = { L"", L"" };

    while (i-- > 0) {
        char length = rand() % count.end + count.start;
        for (char c = 0; c < length; c++) {
            words[i].push_back(' ');
            words[i].push_back(rand() % latin.end + latin.start);
        }
    }

    if (words[0] > words[1]) {
        std::wstring holder = words[1];
        words[1] = words[0];
        words[0] = holder;
    }

    return words;
}

void ShowStrings() {
    out->Clip("strings_replacement");
    out->Target(MAIN)->Page(0)->Line(0);
    out->Text(text)->Line()->Text(Replace())->Line();
    Next();
    std::wstring words[2] = RandomSortedWords();
    out->Clip("strings_sorted_words");
    for (char i = 0; i < 2; i++)
        out->Text(words[i])->Line();
    Next();
}
