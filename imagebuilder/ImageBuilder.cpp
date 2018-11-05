#include <string>
#include "Image.cpp"

class ImageBuilder {
private:
    std::vector<Drawable> drawables_; //Список всех фигур
public:
    Image CreateImage(std::string path, int width, int height) {
        //TODO Загружаем изображение по данному пути, преобразуем в вектор drawables_ и возвращаем объект Image
    }
};