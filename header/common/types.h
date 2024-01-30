#include <windows.h>
#include <string>

#ifndef HEADER_COMMON_TYPES
#define HEADER_COMMON_TYPES

struct Edges { wchar_t left, center, right; };
struct Angles { wchar_t left, right; };
struct Frame {
    Edges horizontal, vertical;
    Angles top, bottom;
    wchar_t cross;
};

struct Vector2u { unsigned int X, Y; };

struct Vector2i { int X, Y; };

struct Range {
    COORD P1, P2;

    Range SwapXY() {
        return {
            { this->P1.X, this->P2.X },
            { this->P1.Y, this->P2.Y }
        };
    }

    Range Swap() {
        return { this->P2, this->P1 };
    };

    Range SwapSizes() {
        return {
            { this->P1.Y, this->P1.X },
            { this->P2.Y, this->P2.X }
        };
    }

    short SumX() { return this->P1.X + this->P2.X; }
    short SumY() { return this->P1.Y + this->P2.Y; }
};

struct Stapler {
    void (*progress)(COORD*, short);
    void (*pins)(COORD*, short);

    void Set(
        void (*line)(COORD*, short),
        void (*points)(COORD*, short)
    ) {
        progress = line;
        pins = points;
    }
};

struct Loop { short start, step, end; };
struct Loop2 {
    Loop X, Y;
    unsigned int count;

    Vector2i Size() {
        Vector2i size;
        size.X = static_cast<int>((X.end - X.start) / X.step) + 1;
        size.Y = static_cast<int>((Y.end - Y.start) / Y.step) + 1;
        count = size.X * size.Y;
        return size;
    }
};

class Answer {
private:
    float m_z;

public:
    float X, Y;
    float* Z = NULL;

    void Input(short x, short y) {
        X = 0.1f * x;
        Y = 0.1f * y;
    }

    void Set(float z) {
        m_z = z;
        Z = &m_z;
    }
};

#endif
