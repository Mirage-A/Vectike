#include <string>
#include "Drawable.cpp"
#include <vector>

class Image {
private:
    Color CombineColors(Color oldColor, Color newColor) {
        //TODO рисует цвет newColor с учётом прозрачности
    }
    std::vector<std::vector<Color>> matrix_; //Матрица цветов пикселей
    std::vector<Drawable> drawables_; //Список всех фигур
public:
    Image(std::vector<Drawable> drawables, int width, int height, Color backGround) {
        //Получаем из ImageBuilder список векторов drawables
        //перебираем все пиксели, все векторы и рисуем в матрице image_
        drawables_ = drawables;
        for(int i = 0; i < width; ++i) {
            std::vector<Color> colorVector;
            for(int j = 0; j < height; ++j) {
                colorVector.push_back(backGround);
                for(int k = 0; k < drawables.size(); ++k) {
                    colorVector[j] = CombineColors(colorVector[j], drawables[k].GetPointColor((double) i / (double) width,
                            (double) j / (double) height));
                }
            }
            matrix_.push_back(colorVector);
        }
    }
};