#ifndef VECTIKE_IMAGE_H
#define VECTIKE_IMAGE_H

#include <string>
#include "drawables/drawable.h"
#include <vector>
#include <memory>

class Image {
private:
    //ВАЖНО!
    //В matrix_ используется система координат от левого верхнего угла экрана, ось y направлена вниз
    //В классах Drawable и всей логике используется система координат от левого нижнего угла экрана,
    //ось y направлена вверх
    std::vector<std::vector<Color>> matrix_; //Матрица цветов пикселей
    std::vector<std::shared_ptr<Drawable>> drawables_; //Список всех фигур
    size_t width_, height_;
    Color background_ = Color::EmptyColor();
public:
    Image();

    Image(size_t width, size_t height, Color background, std::vector<std::shared_ptr<Drawable>> &drawables);

    //Изменяем вектор drawables_ на данный
    void SetDrawables(std::vector<std::shared_ptr<Drawable>> &drawables);

    //Заполняет матрицу изображения
    void Render();

    //Возвращает цвет данного пикселя
    Color GetPixelColor(size_t x, size_t y);

    //Изменяет размер изображения и обновляет его
    void SetSize(size_t new_width, size_t new_height);
};

#endif //VECTIKE_IMAGE_H
