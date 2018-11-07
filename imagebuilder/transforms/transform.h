#ifndef VECTIKE_TRANSFORM_H
#define VECTIKE_TRANSFORM_H

#include <memory>

class Drawable;

class Transform {
    virtual void ApplyTo(std::shared_ptr<Drawable> drawable) const = 0;
};


#endif //VECTIKE_TRANSFORM_H
