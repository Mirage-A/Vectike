#include <windows.h> // Включаем необходимый заголовочный файл для Windows-программ
#ifndef VECTIKE_EDITOR_FRAME_H
#define VECTIKE_EDITOR_FRAME_H

class EditorFrame{
public:
    // Оконная процедура
    int WINAPI WindowCreation(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
    void DrawPixel(int x, int y, int r, int g, int b);
    int WINAPI CloseWindow();
    //TODO Окно редактора
};

#endif //VECTIKE_EDITOR_FRAME_H
