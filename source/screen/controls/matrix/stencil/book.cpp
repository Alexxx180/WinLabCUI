#include "screen/controls/matrix/stencil/book.h"

#include <stdexcept>

byte Book :: Head() { return Mark + Span; }

byte Book :: Map(std::vector<Point>& basis) {
    byte last = basis.size() - 1;

    byte current = basis.at(Mark).X;
    byte pattern = basis.at(last).X;

    return current + pattern * Pages;
}

void Book :: BookMark(byte count) {
    if (count != 0) {
        Mark %= count;
        Pages /= count;
    } else {
        throw std::out_of_range("Matrix-Stencil-Book: Division by 0");
    }
}

void Book :: Split(byte column, byte count) {
    Pages = Mark = column;
    BookMark(count);
}

void Book :: Split(byte count) {
    Split(Head(), count);
}

void Book :: Flip(byte count, char direction) {
    byte listing = Pages * count + Mark + direction;
    Split(listing, count);
}
