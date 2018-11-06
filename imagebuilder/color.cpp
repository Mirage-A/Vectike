
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
    k = new_color.GetAlpha() + (1 - this->GetAlpha()) * (1 - new_color.GetAlpha());
    ans.r_ = this->GetRed() * this->GetAlpha() + (new_color.GetRed() - this->GetAlpha() * this->GetRed()) * k;
    ans.g_ = this->GetGreen() * this->GetAlpha() + (new_color.GetGreen() - this->GetAlpha() * this->GetGreen()) * k;
    ans.b_ = this->GetBlue() * this->GetAlpha() + (new_color.GetBlue() - this->GetAlpha() * this->GetBlue()) * k;
    ans.alpha_ = this->GetAlpha() + new_color.GetAlpha() * (1 - this->GetAlpha());
    return ans;
}

double Color::GetRed() const {
    return this->r_;
}

double Color::GetGreen() const {
    return this->g_;
}

double Color::GetBlue() const {
    return this->b_;
}

double Color::GetAlpha() const {
    return this->alpha_;
}
Color Color::EmptyColor() {
    Color c(0, 0, 0, 0);
    return c;
}

Color Color::Black() {
    Color c(1, 0, 0, 0);
    return c;
}

Color Color::White() {
    Color c(1, 255, 255, 255);
    return c;
}

Color Color::Red() {
    Color c(1, 255, 0, 0);
    return c;
}

Color Color::Green() {
    Color c(1, 0, 255, 0);
    return c;
}

Color Color::Blue() {
    Color c(1, 0, 0, 255);
    return c;
}