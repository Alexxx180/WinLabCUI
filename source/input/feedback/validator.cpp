#include "input/feedback/validator.h"

#include <assert.h>

template<typename TYPE>
Validator<TYPE> :: Validator() {
    m_parser.SetBuffer(m_buffer);
    m_processor.SetBuffer(m_buffer);
}

template<typename TYPE>
short Validator<TYPE> :: Validate()
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
