#include "math-utils.h"

double MathUtils::GetAngle(double sin, double cos) {
    if(cos == 1) return 0;
    if(cos == -1) return M_PI/2;
    if(sin < 0) return -acos(cos);
    return acos(cos);

}