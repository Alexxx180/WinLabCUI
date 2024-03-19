#ifndef INPUT_FEEDBACK_VERIFIER
#define INPUT_FEEDBACK_VERIFIER

#include <string>

#include "input/feedback/typer.h"
#include "input/feedback/notifier.h"
#include "input/feedback/validator.h"
#include "input/limiting/boundary.h"

template<class TYPE>
class Verifier : public Typer {
private:
    Validator<TYPE> m_input;
    Boundary<TYPE> m_edges;

    bool m_verified;
    TYPE m_result;

    void Interrupt(std::string message) {
        status.Notify(message);
        char code = Next(ESC);
        status.Notify("status_forward");
    }

public:
    Notifier status;
    const TYPE& result = m_result;

    Verifier() { m_input.SetResult(&m_result); }

    Boundary<TYPE> *const Edges() { return &m_edges; }

    bool IsVerified() { return m_verified; }

    void Bounds(Boundary<TYPE>* edges) { m_edges = *edges; }

    void TypeInput() {
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
};

#endif
