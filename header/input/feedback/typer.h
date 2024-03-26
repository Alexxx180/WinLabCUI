#ifndef INPUT_FEEDBACK_TYPER
#define INPUT_FEEDBACK_TYPER

#include "screen/matrix/tools.h"

class Typer {
    protected:
        virtual void TypeInput() = 0;
        virtual bool IsVerified() = 0;

    public:
        virtual ~Typer() { }

        void Input() {
            screen->Decoration();
            do {
                layer->Target(MAIN);
                TypeInput();
            }
            while (!IsVerified());
        }
};

#endif
