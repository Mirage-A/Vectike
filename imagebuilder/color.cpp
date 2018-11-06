
#include "color.h"

Color::Color(double alpha, double r, double g, double b) {
    this->alpha_ = alpha;
    this->r_ = r;
    this->g_ = g;
    this->b_ = b;
}

Color Color::CombineWith(Color new_color) const {
    double k;
    Color ans(0,0,0,0);
    k = new_color.getAlpha() + (1 - this->getAlpha()) * (1 - new_color.getAlpha());
    ans.r_ = this->getRed() * this->getAlpha() + (new_color.getRed() - this->getAlpha() * this->getRed()) * k;
    ans.g_ = this->getGreen() * this->getAlpha() + (new_color.getGreen() - this->getAlpha() * this->getGreen()) * k;
    ans.b_ = this->getBlue() * this->getAlpha() + (new_color.getBlue() - this->getAlpha() * this->getBlue()) * k;
    ans.alpha_ = this->getAlpha() + new_color.getAlpha() * (1 - this->getAlpha());
    return ans;
}

double Color::getRed() const {
    return this->r_;
}

double Color::getGreen() const {
    return this->g_;
}

double Color::getBlue() const {
    return this->b_;
}

double Color::getAlpha() const {
    return this->alpha_;
}
Color Color::EmptyColor() {
    Color c(0, 0, 0, 0);
    return c;
}

Color Color::Black() {
    Color c(255, 0, 0, 0);
    return c;
}

Color Color::White() {
    Color c(255, 255, 255, 255);
    return c;
}

Color Color::Red() {
    Color c(255, 255, 0, 0);
    return c;
}

Color Color::Green() {
    Color c(255, 0, 255, 0);
    return c;
}

Color Color::Blue() {
    Color c(255, 0, 0, 255);
    return c;
}