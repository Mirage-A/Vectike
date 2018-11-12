#include <iostream>
#include "editor-logic.h"
void EditorLogic::DrawPixel(HDC &dc, size_t x, size_t y, int r, int g, int b) {
    SetPixel(dc, x, y, RGB(r, g, b));
}
void EditorLogic::ChangePictureSize(HDC &dc, size_t w_size, size_t h_size) {

    image_->SetSize(w_size, h_size);
    image_->Render();
    for(int i = 0; i < w_size; ++i) {
        for(int k = 0; k < h_size; ++k) {
            Color my_color = image_->GetPixelColor(i, k);
            DrawPixel(dc, i, k, my_color.GetRed(),my_color.GetGreen(),my_color.GetBlue());
        }
    }
}
void EditorLogic::LoadImage(std::string path, size_t w_size, size_t h_size) {
    std::shared_ptr<Image> ptr(new Image(""));
    image_ = ptr;
    image_->SetSize(w_size, h_size);
    image_->Render();
}
EditorLogic::EditorLogic() {
    std::shared_ptr<Image> ptr(new Image());
    image_ = ptr;
};
