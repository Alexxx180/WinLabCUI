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

        void Interrupt(std::string message);

    public:
        Notifier status;
        const TYPE& result = m_result;

        Verifier();
        bool IsVerified();
        void TypeInput();

        Boundary<TYPE> *const Edges() { return &m_edges; }
        void Bounds(Boundary<TYPE>* edges) { m_edges = *edges; }
};

#endif
