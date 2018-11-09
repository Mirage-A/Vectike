#include "rotate-transform.h"

RotateTransform::RotateTransform(double angle, double center_x, double center_y) {
    angle_ = angle;
    center_x_ = center_x;
    center_y_ = center_y;
}
Point RotateTransform::GetOriginalPoint(Point transformed_point) const {
    double x_original = cos(angle_) * (transformed_point.x - center_x_) +
            sin(angle_) * (transformed_point.y - center_y_) + center_x_;
    double y_original = -sin(angle_) * (transformed_point.x - center_x_) +
            cos(angle_) * (transformed_point.y - center_y_) + center_y_;
    return Point(x_original, y_original);
}