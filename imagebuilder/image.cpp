#include "image.h"


Image::Image(size_t width, size_t height, Color background, std::vector<Drawable> &drawables) {
    width_ = width;
    height_ = height;
    background_ = background;
    drawables_ = drawables;
    for(size_t i = 0; i < width; ++i) {
        std::vector<Color> color_vector;
        for(size_t j = 0; j < height; ++j) {
            color_vector.push_back(background);
        }
        matrix_.push_back(color_vector);
    }
}

void Image::SetDrawables(std::vector<Drawable> &drawables) {
    drawables_ = drawables;
}

void Image::Render() {
    for(size_t i = 0; i < width_; ++i) {
        for(size_t j = 0; j < height_; ++j) {
            matrix_[i][j] = background_;
            for(int k = 0; k < drawables_.size(); ++k) {
                matrix_[i][j] = matrix_[i][j].CombineWith(drawables_[k].GetPointColor((double) i / (double) width_,
                        (double) (height_ - j - 1) / (double) height_));
            }
        }
    }
}