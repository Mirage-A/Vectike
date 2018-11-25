#ifndef VECTIKE_EDITOR_LOGIC_H
#define VECTIKE_EDITOR_LOGIC_H
#include <windows.h>
#include <string>
#include "../imagebuilder/image.h"

class EditorLogic {
public:
    std::shared_ptr<Image> image_;
    EditorLogic();
    void LoadImage(std::string path, size_t w_size, size_t h_size);
    void DrawPixel(HDC &dc, size_t x, size_t y, int r, int g, int b);
    void ChangePictureSize(HDC &dc, size_t w_size, size_t h_size);
    void DrawImage(HDC &dc, size_t w_size, size_t h_size);
};
#endif //VECTIKE_EDITOR_LOGIC_H