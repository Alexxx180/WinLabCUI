#ifndef INPUT_FEEDBACK_FEEDBACK
#define INPUT_FEEDBACK_FEEDBACK

#include <string>

struct Feedback {
    bool Denied;
    std::wstring Error;

    Feedback() {}
    Feedback(bool denied) { Denied = denied; }
};

#endif
