#include "rounded-vector.h"

bool RoundedVector::ContainsPoint(Point p) const {
    return (p.x >= 0 && p.x <= length_ && p.y <= width_/2 && p.y >= -width_/2)
        || (p.x * p.x + p.y * p.y <= MathUtils::sqr(width_/2))
        || ((p.x - length_) * (p.x - length_) + p.y * p.y <= MathUtils::sqr(width_/2));
}

Color RoundedVector::GetPointColor(double x, double y) const {
    return ContainsPoint(GetOriginalPoint(x, y)) ? color_ : Color::EmptyColor();
}