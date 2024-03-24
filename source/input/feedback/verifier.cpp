#include "input/feedback/verifier.h"

template<typename TYPE>
void Verifier<TYPE> :: Interrupt(std::string message) {
    status.Notify(message);
    Next(ESC);
    status.Notify("status_forward");
}

template<typename TYPE>
Verifier<TYPE> :: Verifier() {
    m_input.SetResult(&m_result);
}

template<typename TYPE>
bool Verifier<TYPE> :: IsVerified() {
    return m_verified;
}

template<typename TYPE>
void Verifier<TYPE> :: TypeInput() {
    m_verified = false;

    if (m_input.Validate()) {
        Interrupt("status_error");
        return;
    }

    if (m_edges.Verify(m_result)) {
        Interrupt("status_invalid_data");
        return;
    }

    m_verified = true;
}
