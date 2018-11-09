#include "image-builder.h"
#include "drawables/vector.h"

Image ImageBuilder::CreateImage(std::string path, size_t width, size_t height) {
    //TODO
    std::vector<std::shared_ptr<Drawable>> drawables;
    /*Vector test_vector(0.2, 0.8, 1, 0.4, 0.1, Color::Black());
    std::shared_ptr<Drawable> ptr(&test_vector);
    drawables.push_back(ptr);*/
    Image image(width, height, Color::Green(), drawables);
    image.Render();
    return image;
}