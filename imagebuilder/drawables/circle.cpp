#include "circle.h"

Color Circle::GetPointColor(double x, double y) const {
    Point p = GetOriginalPoint(x, y);
    double sqrange = p.x * p.x + p.y * p.y;
    return (sqrange >= MathUtils::sqr(radius_ - width_ / 2) && sqrange <= MathUtils::sqr(radius_ + width_ / 2)) ?
        color_ : Color::EmptyColor();
}