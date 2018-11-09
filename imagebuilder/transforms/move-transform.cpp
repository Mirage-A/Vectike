#include "move-transform.h"

MoveTransform::MoveTransform(double dx, double dy) {
    dx_ = dx;
    dy_ = dy;
}

Point MoveTransform::GetOriginalPoint(Point transformed_point) const {
    return Point(transformed_point.x - dx_, transformed_point.y - dy_);
}