#include <windows.h> // Включаем необходимый заголовочный файл для Windows-программ
#include "editor-logic.h"

#ifndef VECTIKE_EDITOR_FRAME_H
#define VECTIKE_EDITOR_FRAME_H

class EditorFrame{
private:
    HWND hWnd; // Уникальный идентификатор окна (handle)
    HINSTANCE hInst; // Идентификатор приложения
    MSG msg;
    LPCSTR AppName = "MyProgramm";
public:
    static EditorLogic editor_logic;
    static HDC dc;
    // Оконная процедура
    int WINAPI WindowCreation(HINSTANCE &hInstance, HINSTANCE &hPrevInstance, LPSTR &lpCmdLine, int nCmdShow);
    int WINAPI CloseWindow();
    EditorFrame(HINSTANCE &hInstance, HINSTANCE &hPrevInstance,
                LPSTR &lpCmdLine, int nCmdShow);
    //TODO Окно редактора
};

#endif //VECTIKE_EDITOR_FRAME_H
