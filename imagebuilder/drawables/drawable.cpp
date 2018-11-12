#include "drawable.h"

Point Drawable::GetOriginalPoint(Point transformed_point) const {
    for(auto iter = transforms_.rbegin(); iter != transforms_.rend(); ++iter) {
        transformed_point = iter->get()->GetOriginalPoint(transformed_point);
    }
    return transformed_point;
}

Point Drawable::GetOriginalPoint(double transformed_x, double transformed_y) const {
    Point p(transformed_x, transformed_y);
    return GetOriginalPoint(p);
}

void Drawable::AddTransform(std::shared_ptr<Transform> transform) {
    transforms_.push_back(transform);
}