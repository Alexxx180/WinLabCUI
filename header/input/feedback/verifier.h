#ifndef INPUT_FEEDBACK_VERIFIER
#define INPUT_FEEDBACK_VERIFIER

#include "input/feedback/typer.h"
#include "input/feedback/notifier.h"
#include "input/feedback/validator.h"
#include "input/limiting/boundary.h"

template<class TYPE>
class Verifier : public Typer {
    private:
        Validator<TYPE> m_input;
        Boundary<TYPE> m_edges;
        TYPE m_result;

        void Interrupt(std::string message) {
            status.Notify(message)->Notify("status_forward");
        }
        bool Chain(bool denied, std::string error) {
            if (denied) Interrupt(error);
            return denied;
        }

    protected:
        void Type() {
            bool denied = Chain(m_input.Validate(), "status_error") ||
                Chain(m_edges.Deny(m_result), "status_invalid_data");
            m_verified = !denied;
        }

    public:
        Notifier status;
        const TYPE& result = m_result;
        const Boundary<TYPE>& Edges = m_edges;

        Verifier() {
            m_input.SetResult(&m_result);
        }
        void Bounds(Boundary<TYPE>* edges) {
            m_edges = *edges;
        }
};

#endif
