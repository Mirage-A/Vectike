#include "image.h"


Image::Image(std::vector<Drawable> drawables, int width, int height, Color backGround) {
    drawables_ = drawables;
    for(int i = 0; i < width; ++i) {
        std::vector<Color> color_vector;
        for(int j = 0; j < height; ++j) {
            color_vector.push_back(backGround);
            for(int k = 0; k < drawables.size(); ++k) {
                color_vector[j] = color_vector[j].CombineWith(drawables[k].GetPointColor((double) i / (double) width,
                        (double) j / (double) height));
            }
        }
        matrix_.push_back(color_vector);
    }
}