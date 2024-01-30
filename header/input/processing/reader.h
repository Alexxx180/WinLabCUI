#include "screen/interaction.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <assert.h>

#include "common/texts/errors.h"

#ifndef SCREEN_INTERACTION_READER
#define SCREEN_INTERACTION_READER

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
            wscanf_s(L"%*[^\n]");
            wscanf_s(L"%*c");
            fwprintf(stderr, errors["overflow"].c_str(), MAX_BUFFER);
        }

        return isOverflow;
    }

    bool IsEmpty() {
        m_buffer[--m_length] = '\0';

        bool isEmpty = m_length <= 0;
        if (isEmpty)
            fwprintf(stderr, L"%s\n", errors["empty_string"].c_str());

        return isEmpty;
    }

    void SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
        m_buffer = buffer;
    }
};

#endif
