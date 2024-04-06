#ifndef INPUT_FEEDBACK_TYPER
#define INPUT_FEEDBACK_TYPER

#include "screen/matrix/tools.h"

class Typer {
    protected:
        bool m_verified = false;

        virtual void Type() = 0;

    public:
        const bool& IsVerified = m_verified;

        virtual ~Typer() {}

        void Input() {
            out->Field();
            do {
                out->Target(MAIN)->Move();
                Type();
            }
            while (!IsVerified);
        }
};

#endif
