#ifndef HEADER_COMMON_TYPES
#define HEADER_COMMON_TYPES

#include <windows.h>
#include <string>

#include <ctime>

struct Edges { wchar_t left, center, right; };
struct Angles { wchar_t left, right; };
struct Frame {
    Edges horizontal, vertical;
    Angles top, bottom;
    wchar_t cross;
};

struct Vector2s { short X, Y; };
struct Vector2u { unsigned int X, Y; };

struct Vector2c { unsigned char X, Y; };

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

struct TimeMeasure {
    unsigned char hour; /* hours (0-23)*/
    unsigned char minute; /* minutes (0-59)*/
    unsigned char second; /* seconds (0-59) */

    void Print() {
        wprintf(L"%i:%02i:%02i", hour, minute, second);
    }
};

struct Task2 {
    Vector3d result;
    TimeMeasure legacy, recursive, iterative;

    TimeMeasure Diff(std::tm* x, std::tm* y) {
        unsigned char sec, min, hour;

        hour = static_cast<unsigned char>(y->tm_hour - x->tm_hour);
        min = static_cast<unsigned char>(y->tm_min - x->tm_min);
        sec = static_cast<unsigned char>(y->tm_sec - x->tm_sec);

        TimeMeasure result = { hour, min, sec };
        return result;
    }

    TimeMeasure CalculateTime(void (*realization)(void)) {
        std::time_t current;

        current = std::time(0);
        std::tm* before = std::localtime(&current);

        realization();

        current = std::time(0);
        std::tm* after = std::localtime(&current);

        return Diff(before, after);
    }
};

struct Answer {
    double X;
    Task2 F;
};

struct HoarStack {
    Vector2l part;
    long Left[MAXSTACK], Right[MAXSTACK];
    long Position;

    long PivotIndex() {
        return (part.X + part.Y) >> 1;
    }

    bool IsSmallerOneLeft() {
        return part.X < part.Y;
    }

    bool HasQueries() {
        return Position != 0;
    }

    void Init(long size) {
        Position = 1;
        Left[Position] = 0;
        Right[Position] = size - 1;
    }
    
    void UpdateBounds() {
        part.X = Left[Position];
        part.Y = Right[Position];
        Position--;
    }

    void LeftBound(long wall, long iteration) {
        if (wall > part.X) {
            Position++;
            Left[Position] = part.X;
            Right[Position] = wall;
        }
        part.X = iteration;
    }

    void RightBound(long wall, long iteration) {
        if (wall > part.Y) {
            Position++;
            Left[Position] = wall;
            Right[Position] = part.Y;
        }
        part.Y = iteration;
    }

};

#endif
