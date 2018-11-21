#ifndef VECTIKE_MATH_UTILS_H
#define VECTIKE_MATH_UTILS_H

#include <math.h>
#include "point.h"

class MathUtils {
public:
    static double GetAngle(double sin, double cos);
    static double GetAngle(Point p);
    static double GetRange(Point p);
};

#endif //VECTIKE_MATH_UTILS_H
