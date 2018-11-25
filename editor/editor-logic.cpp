#include <iostream>
#include <ctime>
#include "editor-logic.h"
void EditorLogic::DrawPixel(HDC &dc, size_t x, size_t y, int r, int g, int b) {
    SetPixel(dc, x, y, RGB(r, g, b));
}
void EditorLogic::ChangePictureSize(HDC &dc, size_t w_size, size_t h_size) {

    image_->SetSize(w_size, h_size);
    DrawImage(dc, w_size, h_size);
}
void EditorLogic::LoadImage(std::string path, size_t w_size, size_t h_size) {
    //TODO
    std::shared_ptr<Image> ptr(new Image(""));
    image_ = ptr;
    image_->SetSize(w_size, h_size);
}
void EditorLogic::DrawImage(HDC &dc, size_t w_size, size_t h_size) {
    long st = clock();

    image_->Render();

    long render = clock() - st;
    std::cout << "Rendering (size " << w_size << "x" << h_size << ") finished in " << render << " ms" << std::endl;
    st = clock();

    for(int i = 0; i < w_size; ++i) {
        for(int k = 0; k < h_size; ++k) {
            Color my_color = image_->GetPixelColor(i, k);
            DrawPixel(dc, i, k, my_color.GetRed(),my_color.GetGreen(),my_color.GetBlue());
        }
    }

    long redraw = clock() - st;
    std::cout << "Redrawing (size " << w_size << "x" << h_size << ") finished in " << redraw << " ms" << std::endl;
    std::cout << "Степень неоптимальности:" << std::endl;
    std::cout << "  Егор: " << render / (double) (render + redraw) * 100 << "%" << std::endl;
    std::cout << "  Гриша: " << redraw / (double) (render + redraw) * 100 << "%" << std::endl;
    std::string dibilushka_name = render < redraw ? "Гриша" : "Егор";
    std::cout << dibilushka_name << " дибилушка, оптимизируй свой донный код!" << std::endl;
    std::cout << std::endl;
}
EditorLogic::EditorLogic() {
    std::shared_ptr<Image> ptr(new Image());
    image_ = ptr;
};