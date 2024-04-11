#ifndef SCREEN_CONTROLS_MATRIX_PEN
#define SCREEN_CONTROLS_MATRIX_PEN

#include "common/texts/common.h"
#include "screen/controls/matrix/pen/formatter.h"
#include "input/feedback/limiting/boundary.h"

class Pen : public Formatter {
    protected:
        Pen() {}

    public:
        static Pen& Pen :: ink() {
            static Pen instance;
            return instance;
        }

        Pen* Clip(std::string name) {
            Text(texts.at(name));
            return this;
        }

        Pen* Typo(int position) {
            const wchar_t* ident = L"%*c";
            fwprintf(stderr, ident, position, 'v');
            return this;
        }

        template<typename TYPE>
        Pen* Bounds(Boundary<TYPE>& limits) {
            Text(L"<", limits.start, L", ", limits.end, L">");
            return this;
        }

        template<typename TYPE>
        Pen* FBounds(const wchar_t* format, Boundary<TYPE>& limits) {
            Text(L"<");
            FText(format, limits.start);
            Text(L", ");
            FText(format, limits.end);
            Text(L">");
            return this;
        }
};

#endif
