
#include "vector.h"

Vector::Vector(double x1, double y1, double x2, double y2, double width, Color color) {
    x1_ = x1;
    y1_ = y1;
    x2_ = x2;
    y2_ = y2;
    width_ = width;
    color_ = color;
}

Color Vector::GetPointColor(double x, double y) const {
    //TODO
    if(y - x <= 0) return color_;
    return Color::EmptyColor();
}
void Vector::Move(double dx, double dy) {
    x1_ += dx;
    y1_ += dy;
    x2_ += dx;
    y2_ += dy;
}
void Vector::Rotate(double angle, double center_x, double center_y) {
    //TODO
}
void Vector::AddTransform(Transform transform) {
    transforms_.push_back(transform);
}