#ifndef VECTIKE_IMAGE_BUILDER_H
#define VECTIKE_IMAGE_BUILDER_H

#include <string>
#include "image.h"

class ImageBuilder {
private:
    std::vector<Drawable> drawables_; //Список всех фигур
public:
    //TODO Загружаем изображение по данному пути, преобразуем в вектор drawables_ и возвращаем объект image
    Image CreateImage(std::string path, int width, int height);
};

#endif //VECTIKE_IMAGE_BUILDER_H
