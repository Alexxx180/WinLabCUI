#ifndef SCREEN_CONTROLS_MATRIX_PEN
#define SCREEN_CONTROLS_MATRIX_PEN

#include <string>

#include "screen/controls/matrix/pen/formatter.h"
#include "input/limiting/boundary.h"

class Pen : public Formatter {
    protected:
        Pen();

    public:
        typedef Pen* (Pen::*quoteptr)(std::string);

        static Pen* ink();
        quoteptr Feedback();

        Pen* Clip(std::string name);

        template<typename TYPE>
        Pen* Bounds(Boundary<TYPE>& limits);
};

#endif
