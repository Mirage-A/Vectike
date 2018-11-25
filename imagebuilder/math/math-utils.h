#ifndef VECTIKE_MATH_UTILS_H
#define VECTIKE_MATH_UTILS_H

#include <math.h>
#include "point.h"

class MathUtils {
public:
    static inline double GetAngle(double sin, double cos) {
        if(cos == 1) return 0;
        if(cos == -1) return M_PI/2;
        if(sin < 0) return -acos(cos);
        return acos(cos);

    }
    static inline double GetAngle(Point p) {
        double range = GetRange(p);
        if (range == 0) return 0;
        return GetAngle(p.y / range, p.x / range);
    }
    static inline double GetRange(Point p) {
        return sqrt(p.x * p.x + p.y * p.y);
    }
    static inline double sqr(double a) {
        return a * a;
    }
};

#endif //VECTIKE_MATH_UTILS_H
