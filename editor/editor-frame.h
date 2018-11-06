//
// Created by Егор on 06.11.2018.
//
#include <windows.h> // Включаем необходимый заголовочный файл для Windows-программ
#ifndef VECTIKE_EDITOR_FRAME_H
#define VECTIKE_EDITOR_FRAME_H

class EditorFrame{
private:
    // Объявление функции окна (оконной процедуры)
    LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
public:
    // Оконная процедура
    int WINAPI WindowCreation(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                       LPSTR lpCmdLine, int nCmdShow);
    //TODO Окно редактора
};

#endif //VECTIKE_EDITOR_FRAME_H
