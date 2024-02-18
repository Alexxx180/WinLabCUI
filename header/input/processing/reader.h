#ifndef SCREEN_INTERACTION_READER
#define SCREEN_INTERACTION_READER

#include <stdio.h>
#include <conio.h>
#include <string>

#include "screen/interaction.h"
#include "common/texts/errors.h"

class Reader {
private:
    wchar_t* m_buffer;
    size_t m_length;

public:
    bool NotReadable() {
        return !fgetws(m_buffer, ACTUAL_MAX, stdin);
    }

    bool IsOverflow() {
        // Skip string remainder
        m_length = wcslen(m_buffer);
        bool isOverflow = m_buffer[m_length - 1] != '\n';

        if (isOverflow) {
            std::wstring text = errors["overflow"];
            wscanf_s(L"%*[^\n]");
            wscanf_s(L"%*c");
            fwprintf(stderr, text.c_str(), MAX_BUFFER);
        }

        return isOverflow;
    }

    bool IsEmpty() {
        m_buffer[--m_length] = '\0';

        bool isEmpty = m_length <= 0;
        if (isEmpty) {
            std::wstring text = errors["empty_string"];
            fwprintf(stderr, L"%s\n", text.c_str());
        }

        return isEmpty;
    }

    void SetBuffer(wchar_t buffer[ACTUAL_MAX]) { m_buffer = buffer; }
};

#endif
