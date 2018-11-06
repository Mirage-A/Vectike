#ifndef VECTIKE_IMAGE_BUILDER_H
#define VECTIKE_IMAGE_BUILDER_H

#include <string>
#include "image.h"

class ImageBuilder {
public:
    //TODO Загружаем изображение по данному пути и возвращаем объект image
    static Image CreateImage(std::string path, size_t width, size_t height);
};

#endif //VECTIKE_IMAGE_BUILDER_H
