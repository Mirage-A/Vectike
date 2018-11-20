#include "circle.h"

Color Circle::GetPointColor(double x, double y) const {
    Point p = GetOriginalPoint(x, y);
    double range = sqrt(p.x * p.x + p.y * p.y);
    return (range >= radius_ - width_ / 2 && range <= radius_ + width_ / 2) ? color_ : Color::EmptyColor();
}