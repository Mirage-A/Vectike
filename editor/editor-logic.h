//
// Created by гриша on 09.11.2018.
//

#ifndef VECTIKE_EDITOR_LOGIC_H
#define VECTIKE_EDITOR_LOGIC_H
#include <windows.h>
#include "../imagebuilder/image-builder.h"
#include <string>

class EditorLogic {
private:
    Image image_;
public:
    EditorLogic();
    void LoadImage(std::string path, size_t w_size, size_t h_size);
    void DrawPixel(HDC dc, int x, int y, int r, int g, int b);
    void ChangePictureSize(HDC dc, size_t w_size, size_t h_size);
};
#endif //VECTIKE_EDITOR_LOGIC_H