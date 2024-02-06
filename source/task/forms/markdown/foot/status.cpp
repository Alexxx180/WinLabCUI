#include "task/forms/markdown/foot/status.h"

#include <vector>
#include "screen/matrix/types/point.h"

std::vector<Point> StatusAlert(unsigned char x, Point p2) {
    std::vector<Point> alert;

    Point item = { x, p2.Y - 1 };

    alert.push_back(item);

    item.X = p2.X - margin;

    alert.push_back(item);

    return alert;
}

std::vector<Point> StatusTable(Point item, unsigned char x) {
    std::vector<Point> controls = { item };

    item.X = x * 1 / 3 + margin;

    controls.push_back(item);

    item.X = x * 2 / 3 + margin;

    controls.push_back(item);

    return controls;
}
