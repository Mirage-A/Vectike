#include "move-transform.h"
#include "drawable.h"

MoveTransform::MoveTransform(double dx, double dy) {
    dx_ = dx;
    dy_ = dy;
}

void MoveTransform::ApplyTo(Drawable drawable) const {
    drawable.Move(dx_, dy_);
}