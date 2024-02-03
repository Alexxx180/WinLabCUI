#ifndef SCREEN_INTERACTION_READER
#define SCREEN_INTERACTION_READER

#include <stdio.h>
#include <conio.h>
#include <string.h>

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
            wchar_t* text = errors["overflow"].c_str();
            wscanf_s(L"%*[^\n]");
            wscanf_s(L"%*c");
            fwprintf(stderr, text, MAX_BUFFER);
        }

        return isOverflow;
    }

    bool IsEmpty() {
        m_buffer[--m_length] = '\0';

        bool isEmpty = m_length <= 0;
        if (isEmpty) {
            wchar_t* text = errors["empty_string"].c_str();
            fwprintf(stderr, L"%s\n", text);
        }

        return isEmpty;
    }

    void SetBuffer(wchar_t buffer[ACTUAL_MAX]) { m_buffer = buffer; }
};

#endif
