#ifndef VECTIKE_MOVE_TRANSFORM_H
#define VECTIKE_MOVE_TRANSFORM_H

#include "transform.h"

class MoveTransform : public Transform {
private:
    double dx_, dy_;
public:
    MoveTransform(double dx, double dy);
    Point GetOriginalPoint(Point transformed_point) const;
};

#endif //VECTIKE_MOVE_TRANSFORM_H
