#ifndef VECTIKE_ROTATE_TRANSFORM_H
#define VECTIKE_ROTATE_TRANSFORM_H

#include "transform.h"

class RotateTransform : public Transform {
private:
    double angle_, center_x_, center_y_;
public:
    RotateTransform(double angle, double center_x, double center_y);
    void ApplyTo(Drawable drawable) const;
};

#endif //VECTIKE_ROTATE_TRANSFORM_H
