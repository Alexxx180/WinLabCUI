#ifndef SCREEN_CONTROLS_MATRIX_PEN
#define SCREEN_CONTROLS_MATRIX_PEN

#include <string>

#include "common/texts/common.h"
#include "screen/controls/matrix/pen/formatter.h"
#include "input/limiting/boundary.h"

class Pen : public Formatter {
    protected:
        Pen() {}

    public:
        typedef Pen* (Pen::*quoteptr)(std::string);

        static Pen& Pen :: ink() {
            static Pen instance;
            return instance;
        }

        quoteptr Feedback() {
            return &Pen::Clip;
        }

        Pen* Clip(std::string name) {
            Text(texts.at(name));
            return this;
        }

        template<typename TYPE>
        Pen* Bounds(Boundary<TYPE>& limits) {
            Text(L"<", limits.start, L", ", limits.end, L">");
            return this;
        }
};

#endif
