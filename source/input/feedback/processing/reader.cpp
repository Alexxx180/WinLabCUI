#include "input/feedback/processing/reader.h"

#include <stdio.h>
#include <conio.h>

#include "common/texts/errors.h"

bool Reader :: NotReadable(std::wstring* text) {
    bool notReadable = !fgetws(m_buffer, ACTUAL_MAX, stdin);

    if (notReadable) *text = errors.at("invalid_data");
    return notReadable;
}

bool Reader :: IsOverflow(std::wstring* text) {
    m_length = wcslen(m_buffer);

    bool isOverflow = m_buffer[m_length - 1] != '\n';

    if (isOverflow) {
        // Avoid extra input
        wscanf_s(L"%*[^\n]");
        wscanf_s(L"%*c");
        *text = errors.at("overflow") + SMAX_BUFFER;
    }
    return isOverflow;
}

bool Reader :: IsEmpty(std::wstring* text) {
    m_buffer[--m_length] = '\0';

    bool isEmpty = m_length <= 0;

    if (isEmpty) *text = errors.at("empty_string");
    return isEmpty;
}

Feedback Reader :: Interrupt() {
    std::wstring text = L"OK";

    Feedback input(NotReadable(&text) || IsOverflow(&text) || IsEmpty(&text));
    input.Error = text;
    return input;
}

void Reader :: SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
    m_buffer = buffer;
}
