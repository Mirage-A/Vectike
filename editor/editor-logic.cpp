//
// Created by гриша on 09.11.2018.
//

#include "editor-logic.h"
void EditorLogic::DrawPixel(HDC dc, int x, int y, int r, int g, int b) {
    SetPixel(dc, x, y, RGB(r, g, b));
}
void EditorLogic::ChangePictureSize(HDC dc, size_t w_size, size_t h_size) {
    image_.SetSize(w_size, h_size);
    for(int i = 0; i < w_size; ++i) {
        for(int k = 0; k < h_size; ++k) {
            Color my_color = image_.GetPixelColor(i, k);
            DrawPixel(dc, i, k, my_color.GetRed(),my_color.GetGreen(),my_color.GetBlue());
        }
    }
}
void EditorLogic::LoadImage(std::string path, size_t w_size, size_t h_size) {
    image_ = ImageBuilder::CreateImage(path, w_size, h_size);
}
EditorLogic::EditorLogic() {
    image_ = Image();
};
