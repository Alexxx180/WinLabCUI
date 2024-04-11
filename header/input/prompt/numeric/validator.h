#ifndef INPUT_FEEDBACK_VALIDATOR
#define INPUT_FEEDBACK_VALIDATOR

#include <assert.h>

#include "input/feedback/processing/converter.h"
#include "input/feedback/processing/reader.h"
#include "input/feedback/limiting/buffer.h"
#include "screen/interaction/interaction.h"

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

        Feedback Validate()
        {
            // Parameters assert
            assert(m_result);
            fflush(stdout);
            // Read into buffer
            {
                Feedback input = m_parser.Interrupt();
                if (input.Denied) return input;
            }
            // Convert string into number
            errno = 0;
            m_processor.Convert(m_result);
            return m_processor.HasInvalidData();
        }

        void SetResult(TYPE* result) {
            m_result = result;
        }
};

#endif
