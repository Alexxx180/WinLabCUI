#ifndef INPUT_FEEDBACK_VALIDATOR
#define INPUT_FEEDBACK_VALIDATOR

#include <assert.h>

#include "input/processing/converter.h"
#include "input/processing/reader.h"
#include "screen/interaction.h"

template<typename TYPE>
class Validator {
private:
    Reader m_parser;
    Converter<TYPE> m_processor;
    wchar_t m_buffer[ACTUAL_MAX];
    TYPE* m_result;

public:
    Validator() {
        m_parser.SetBuffer(m_buffer);
        m_processor.SetBuffer(m_buffer);
    }

    void SetResult(TYPE* result) { m_result = result; }

    short Validate()
    {
        // Parameters assert
        assert(m_result);
        fflush(stdout);

        // Read into buffer
        if (m_parser.NotReadable()) return true;
        if (m_parser.IsOverflow()) return true;
        if (m_parser.IsEmpty()) return true;

        // Convert string into number
        errno = 0;
        m_processor.Convert(m_result);

        return m_processor.HasInvalidData();
    }
};

#endif
