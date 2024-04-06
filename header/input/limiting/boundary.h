#ifndef INPUT_LIMITING_BOUNDARY
#define INPUT_LIMITING_BOUNDARY

#include "common/texts/errors.h"
#include "input/feedback/feedback.h"

template<typename TYPE>
struct Boundary {
    TYPE start, end;

    Boundary() {}
    Boundary(TYPE p1, TYPE p2) {
        Set(p1, p2);
    }

    std::wstring OutBound(std::string text) {
        std::wstring result(text.begin(), text.end());
        return errors.at("out_of_bounds") + result;
    }

    std::string ToString() {
        return "<" + std::to_string(start) + ", " + std::to_string(end) + ">";
    }

    bool Deny(TYPE target) {
        return target < start || target > end;
    }

    Feedback Describe(TYPE target) {
        std::string text = ToString();
        std::string no = std::to_string(target);
        Feedback input;
        input.Denied = target < start;
        if (input.Denied)
            input.Error = OutBound(" " + no + " " + text);
        else if (input.Denied = target > end)
            input.Error = OutBound(" " + text + " " + no);
        return input;
    }

    void Set(TYPE p1, TYPE p2) {
        start = p1;
        end = p2;
    }
};

#endif
