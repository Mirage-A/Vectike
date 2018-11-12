#ifndef VECTIKE_ROUNDED_VECTOR_H
#define VECTIKE_ROUNDED_VECTOR_H

#include "vector.h"

class RoundedVector : public Vector {
private:
    bool ContainsPoint(Point p) const;
public:
    RoundedVector(double x1, double y1, double x2, double y2, double width, Color color) :
        Vector(x1, y1, x2, y2, width, color) {};

    RoundedVector(double length, double width, Color color) :
        Vector(length, width, color) {};

    virtual Color GetPointColor(double x, double y) const override;
};

#endif //VECTIKE_ROUNDED_VECTOR_H
