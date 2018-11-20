#include "group.h"
#include "vector.h"
#include "filled-circle.h"

Color Group::GetPointColor(double x, double y) const {
    Point p = GetOriginalPoint(x, y);
    Color color = Color::EmptyColor();
    for (auto draw : drawables_list_) {
        color = color.CombineWith(draw->GetPointColor(p.x, p.y));
    }
    return color;
}