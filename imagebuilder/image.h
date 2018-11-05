#ifndef VECTIKE_IMAGE_H
#define VECTIKE_IMAGE_H

#include <string>
#include "drawable.h"
#include <vector>

class Image {
private:
    std::vector<std::vector<Color>> matrix_; //Матрица цветов пикселей
    std::vector<Drawable> drawables_; //Список всех фигур
public:
    //Получаем из image-builder список векторов drawables
    //перебираем все пиксели, все векторы и рисуем в матрице image_
    Image(std::vector<Drawable> drawables, int width, int height, Color backGround);
};

#endif //VECTIKE_IMAGE_H
