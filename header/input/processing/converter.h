#include "screen/interaction.h"

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <assert.h>

#include "common/texts/errors.h"

#ifndef SCREEN_INTERACTION_CONVERTER
#define SCREEN_INTERACTION_CONVERTER

template<typename TYPE>
class Converter {
private:
    static const short system = 10;
    wchar_t* m_end = NULL;
    wchar_t* m_buffer;

    void MarkCharacter() {
        fwprintf(stderr, L"\t%*c\n", (int)(m_end - m_buffer) + 1, '^');
    }

public:
    bool HasInvalidData() {
        bool isInvalid = errno != 0 || *m_end != '\0';

        if (isInvalid)
        {
            fwprintf(stderr, L"%s\n", errors["invalid_character"].c_str());
            fwprintf(stderr, L"\t%s\n", m_buffer);
            MarkCharacter();
        }

        return isInvalid;
    }

    void SetBuffer(wchar_t buffer[ACTUAL_MAX]) {
        m_buffer = buffer;
    }

    template <typename TYPE>
    void Convert(TYPE* value) { }

    template <>
    void Convert(short* value)
    {
        *value = wcstol(m_buffer, &m_end, system);
    }

    template <>
    void Convert(float* value)
    {
        *value = wcstof(m_buffer, &m_end);
    }
};

#endif
