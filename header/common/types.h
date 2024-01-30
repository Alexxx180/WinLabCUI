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

struct Vector2s { short X, Y; };
struct Vector2u { unsigned int X, Y; };

struct Vector2i { int X, Y; };

struct Vector3d { double X, Y, Z; };

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

struct Period {
    Vector2s precision;
    double x;
};

struct Task2 {
    Vector3d result;
    dostime legacy, recursive, iterative;

    static dostime Diff(dostime before, dostime after) {
        dostime result = {
            after.hour - before.hour,
            after.minute - before.minute,
            after.second - before.second,
            after.hsecond - before.hsecond
        };
        return result;
    }
};

struct Answer {
    double X;
    Task2 F;
};

#endif
