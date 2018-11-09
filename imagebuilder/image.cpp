#include "image.h"
#include "drawables/vector.h"

Image::Image(size_t width, size_t height, Color background, std::vector<std::shared_ptr<Drawable>> &drawables) {
    width_ = 0;
    height_ = 0;
    SetSize(width, height);
    background_ = background;
    drawables_ = drawables;
}

Image::Image() {
    width_ = 0;
    height_ = 0;
    background_ = Color::EmptyColor();
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
    if(new_width > width_) {
        for(size_t i = width_; i < new_width; ++i) {
            std::vector<Color> color_vector;
            for(size_t j = 0; j < height_; ++j) {
                color_vector.push_back(background_);
            }
            matrix_.push_back(color_vector);
        }
    }
    else{
        for(size_t i = width_; i > new_width; --i){
            matrix_.pop_back();
        }
    }
    if(new_height > height_) {
        for(size_t i = 0; i < new_width; ++i) {
            for(size_t j = height_; j < new_height; ++j) {
                matrix_[i].push_back(background_);
            }
        }
    }
    else{
        for(size_t i = 0; i < new_width; ++i) {
            for(size_t j = height_; j > new_height; --j) {
                matrix_[i].pop_back();
            }
        }
    }

    width_ = new_width;
    height_ = new_height;
}