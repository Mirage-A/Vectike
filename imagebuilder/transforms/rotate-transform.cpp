#include "rotate-transform.h"
#include "../drawables/drawable.h"

RotateTransform::RotateTransform(double angle, double center_x, double center_y) {
    angle_ = angle;
    center_x_ = center_x;
    center_y_ = center_y;
}
void RotateTransform::ApplyTo(Drawable drawable) const {
    drawable.Rotate(angle_, center_x_, center_y_);
}