#include "image.h"
#include "drawables/vector.h"

Image::Image(size_t width, size_t height, Color background, std::vector<std::shared_ptr<Drawable>> &drawables) {
    SetSize(width, height);
    background_ = background;
    drawables_ = drawables;
}

void Image::SetDrawables(std::vector<std::shared_ptr<Drawable>> &drawables) {
    drawables_ = drawables;
}

void Image::Render() {
    for(size_t i = 0; i < width_; ++i) {
        for(size_t j = 0; j < height_; ++j) {
            matrix_[i][j] = background_;
            for(int k = 0; k < drawables_.size(); ++k) {
                matrix_[i][j] = matrix_[i][j].CombineWith(drawables_[k]->GetPointColor((double) i / (double) width_,
                        (double) (height_ - j - 1) / (double) height_));
            }
        }
    }
}

Color Image::GetPixelColor(size_t x, size_t y) {
    return matrix_[x][y];
}

void Image::SetSize(size_t new_width, size_t new_height) {
    width_ = new_width;
    height_ = new_height;
    for(size_t i = 0; i < width_; ++i) {
        std::vector<Color> color_vector;
        for(size_t j = 0; j < height_; ++j) {
            color_vector.push_back(background_);
        }
        matrix_.push_back(color_vector);
    }
}