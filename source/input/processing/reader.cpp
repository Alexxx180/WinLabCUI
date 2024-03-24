#include "input/processing/reader.h"

#include <stdio.h>
#include <conio.h>
#include <string>

#include "common/texts/errors.h"

bool Reader :: NotReadable() {
    return !fgetws(m_buffer, ACTUAL_MAX, stdin);
}

bool Reader :: IsOverflow() {
    // Skip string remainder
    m_length = wcslen(m_buffer);
    bool isOverflow = m_buffer[m_length - 1] != '\n';

    if (isOverflow) {
        std::wstring text = errors.at("overflow");
        wscanf_s(L"%*[^\n]");
        wscanf_s(L"%*c");
        fwprintf(stderr, text.c_str(), MAX_BUFFER);
    }

    return isOverflow;
}

bool Reader :: IsEmpty() {
    m_buffer[--m_length] = '\0';

    bool isEmpty = m_length <= 0;
    if (isEmpty) {
        std::wstring text = errors.at("empty_string");
        fwprintf(stderr, L"%s\n", text.c_str());
    }

    return isEmpty;
}

void Reader :: SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
    m_buffer = buffer;
}
