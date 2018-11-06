
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
    k = new_color.alpha_ + (1 - this->alpha_) * (1 - new_color.alpha_);
    ans.r_ = this->r_ * this->alpha_ + (new_color.r_ - this->alpha_ * this->r_) * k;
    ans.g_ = this->g_ * this->alpha_ + (new_color.g_ - this->alpha_ * this->g_) * k;
    ans.b_ = this->b_ * this->alpha_ + (new_color.b_ - this->alpha_ * this->b_) * k;
    ans.alpha_ = this->alpha_ + new_color.alpha_ * (1 - this->alpha_);
    return ans;
}