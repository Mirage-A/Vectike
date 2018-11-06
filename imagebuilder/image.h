#ifndef VECTIKE_IMAGE_H
#define VECTIKE_IMAGE_H

#include <string>
#include "drawable.h"
#include <vector>

class Image {
private:
    //ВАЖНО!
    //В matrix_ используется система координат от левого верхнего угла экрана, ось y направлена вниз
    //В классах Drawable и всей логике используется система координат от левого нижнего угла экрана,
    //ось y направлена вверх
    std::vector<std::vector<Color>> matrix_; //Матрица цветов пикселей
    std::vector<Drawable> drawables_; //Список всех фигур
    size_t width_, height_;
    Color background_ = Color::EmptyColor();
public:
    Image(size_t width, size_t height, Color background, std::vector<Drawable> &drawables);

    //Изменяем вектор drawables_ на данный
    void SetDrawables(std::vector<Drawable> &drawables);

    //Заполняет матрицу изображения
    void Render();

    Color GetPixelColor(size_t x, size_t y);
};

#endif //VECTIKE_IMAGE_H
