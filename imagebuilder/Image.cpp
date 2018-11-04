#include <string>
#include "Color.cpp"
#include "Drawable.cpp"
#include <vector>

class Image {
private:
    Color **image_; //Матрица цветов пикселей
    std::vector<Drawable> drawables_; //Список всех фигур
public:
    Image(std::vector<Drawable> drawables, int width, int height){
        //TODO Получаем из ImageBuilder список векторов drawables
        //TODO перебираем все пиксели, все векторы и рисуем в матрице image_
    }
};