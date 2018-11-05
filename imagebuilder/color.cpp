
#include "color.h"

Color::Color(double alpha, double r, double g, double b) {
    this->alpha_ = alpha;
    this->r_ = r;
    this->g_ = g;
    this->b_ = b;
}

Color Color::CombineWith(Color new_color) const {
    return Color::EmptyColor();
}