#include "image-builder.h"
#include "vector.h"

Image ImageBuilder::CreateImage(std::string path, size_t width, size_t height) {
    std::vector<Drawable> drawables;
    Vector test_vector(0, 0, 0.8, 0.4, 0.16, Color::Black());
    drawables.push_back(test_vector);
    Image image(width, height, Color::Green(), drawables);
    image.Render();
    return image;
}