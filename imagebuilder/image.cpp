#include <iostream>
#include "image.h"
#include "drawables/rounded-vector.h"
#include "drawables/circle.h"
#include "drawables/group.h"

Image::Image(size_t width, size_t height, Color background, std::vector<std::shared_ptr<Drawable>> &drawables) :
        width_(width), height_(height), background_(background),drawables_(drawables) {
    SetSize(width, height);
}

Image::Image() :
    width_(0), height_(0), background_(Color::EmptyColor()) {}

Image::Image(std::string path) : background_(Color::EmptyColor()){
    //TODO загрузка изображения из файла
    width_ = 0;
    height_ = 0;
    background_ = Color(0.1, 255, 0, 0);
    std::vector<Drawable*> tmp {
        new RoundedVector(0.3, 0.8, 0.3, 0.6, 0.05, Color::Red()),
        new RoundedVector(0.3, 0.8, 0.4, 0.8, 0.05, Color::Red()),

        new Circle(0.6, 0.7, 0.1, 0.05, Color::Blue()),

        new RoundedVector(0.03, 0.5, 0.03, 0.3, 0.03, Color::Black()),
        new RoundedVector(0.03, 0.4, 0.13, 0.5, 0.03, Color::Black()),
        new RoundedVector(0.03, 0.4, 0.13, 0.3, 0.03, Color::Black()),

        new Circle(0.24, 0.4, 0.1, 0.03, Color::Green()),

        new RoundedVector(0.34, 0.3, 0.50, 0.3, 0.03, Color::White()),
        new RoundedVector(0.38, 0.3, 0.42, 0.5, 0.03, Color::White()),
        new RoundedVector(0.46, 0.3, 0.42, 0.5, 0.03, Color::White()),

        new RoundedVector(0.54, 0.3, 0.54, 0.5, 0.03, Color::Magenta()),
        new RoundedVector(0.54, 0.3, 0.65, 0.5, 0.03, Color::Magenta()),
        new RoundedVector(0.65, 0.3, 0.65, 0.5, 0.03, Color::Magenta()),

        new RoundedVector(0.74, 0.3, 0.74, 0.5, 0.03, Color::Orange()),
        new RoundedVector(0.69, 0.5, 0.79, 0.5, 0.03, Color::Orange()),

        new RoundedVector(0.85, 0.35, 0.85, 0.5, 0.03, Color::Cyan()),
        new Circle(0.9, 0.35, 0.05, 0.03, Color::Cyan())

    };
    std::shared_ptr<Group> group = std::shared_ptr<Group>(new Group());
    for (Drawable* it : tmp) {
        group->drawables_list_.push_back(std::shared_ptr<Drawable>(it));
    }
    drawables_.push_back(group);
}
void Image::SetDrawables(std::vector<std::shared_ptr<Drawable>> &drawables) {
    drawables_ = drawables;
}

void Image::Render() {
    for(size_t i = 0; i < width_; ++i) {
        for(size_t j = 0; j < height_; ++j) {
            matrix_[i][j] = Color::White().CombineWith(background_);
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