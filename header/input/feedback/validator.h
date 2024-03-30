#ifndef INPUT_FEEDBACK_VALIDATOR
#define INPUT_FEEDBACK_VALIDATOR

#include <assert.h>

#include "input/processing/converter.h"
#include "input/processing/reader.h"
#include "input/limiting/buffer.h"

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

        bool Validate()
        {
            // Parameters assert
            errno = 0;
            assert(m_result);
            fflush(stdout);
            // Read into buffer
            if (m_parser.Interrupt()) return true;
            // Convert string into number
            m_processor.Convert(m_result);
            return m_processor.HasInvalidData();
        }

        void SetResult(TYPE* result) {
            m_result = result;
        }
};

#endif
