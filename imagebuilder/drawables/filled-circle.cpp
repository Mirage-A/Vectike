#include "filled-circle.h"

Color FilledCircle::GetPointColor(double x, double y) const {
    Point p = GetOriginalPoint(x, y);
    double sqrange = p.x * p.x + p.y * p.y;
    return (sqrange <= MathUtils::sqr(radius_)) ? color_ : Color::EmptyColor();
}