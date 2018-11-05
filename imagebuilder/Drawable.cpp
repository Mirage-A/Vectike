#ifndef FOO_H_INCLUDED /* any name uniquely mapped to file name */
#define FOO_H_INCLUDED

#include "Color.cpp"
#include "Transform.cpp"

class Drawable{
public:
    virtual Color GetPointColor(double x, double y);
    virtual void Move(double dx, double dy);
    virtual void Rotate(double angle);
    virtual void AddTransform(Transform transform);

};

#endif