#ifndef INPUT_FEEDBACK_VERIFIER
#define INPUT_FEEDBACK_VERIFIER

#include "input/feedback/typer.h"
#include "input/feedback/notifier.h"
#include "input/feedback/limiting/boundary.h"
#include "input/prompt/numeric/validator.h"

template<class TYPE>
class Verifier : public Typer {
    private:
        Validator<TYPE> m_input;
        Boundary<TYPE> m_edges;
        TYPE m_result;

        void Binding() { m_input.SetResult(&m_result); }

    protected:
        void Type() {
            bool denied = status.Chain(&m_input.Validate()) ||
                status.Chain(&m_edges.Describe(m_result));
            m_verified = !denied;
        }

    public:
        Notifier status;
        const TYPE& result = m_result;
        const Boundary<TYPE>& Edges = m_edges;

        Verifier() { Binding(); }

        Verifier(Boundary<TYPE>& edges) {
            Binding();
            Bounds(edges);
        }

        void Bounds(Boundary<TYPE>& edges) {
            m_edges = edges;
        }
};

#endif
