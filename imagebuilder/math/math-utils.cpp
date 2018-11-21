#include "math-utils.h"

double MathUtils::GetAngle(double sin, double cos) {
    if(cos == 1) return 0;
    if(cos == -1) return M_PI/2;
    if(sin < 0) return -acos(cos);
    return acos(cos);

}

double MathUtils::GetAngle(Point p) {
    double range = GetRange(p);
    if (range == 0) return 0;
    return GetAngle(p.y / range, p.x / range);
}

double MathUtils::GetRange(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}