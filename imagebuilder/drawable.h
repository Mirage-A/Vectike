//
// Created by Егор on 06.11.2018.
//

#ifndef VECTIKE_DRAWABLE_H
#define VECTIKE_DRAWABLE_H

#include "color.h"
#include "transform.h"

class Drawable{
public:
    virtual Color GetPointColor(double x, double y) const;
    virtual void Move(double dx, double dy);
    virtual void Rotate(double angle, double center_x, double center_y);
    virtual void AddTransform(Transform transform);

};

#endif //VECTIKE_DRAWABLE_H
