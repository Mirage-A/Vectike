#include "filled-circle.h"

Color FilledCircle::GetPointColor(double x, double y) const {
    Point p = GetOriginalPoint(x, y);
    double range = sqrt(p.x * p.x + p.y * p.y);
    return (range <= radius_) ? color_ : Color::EmptyColor();
}