#ifndef VECTIKE_MOVE_TRANSFORM_H
#define VECTIKE_MOVE_TRANSFORM_H

#include "transform.h"

class MoveTransform : public Transform {
private:
    double dx_, dy_;
public:
    MoveTransform(double dx, double dy);
    void ApplyTo(std::shared_ptr<Drawable> drawable) const;
};

#endif //VECTIKE_MOVE_TRANSFORM_H
