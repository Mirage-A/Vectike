
#include "drawable.h"

Color Drawable::GetPointColor(double x, double y) const {
    return Color::EmptyColor();
}
void Drawable::Move(double dx, double dy) {}
void Drawable::Rotate(double angle, double center_x, double center_y) {}
void Drawable::AddTransform(Transform transform) {}