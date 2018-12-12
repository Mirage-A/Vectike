#include <iostream>
#include <vector>
#include "editor/editor-frame.h"
#include <windows.h>
using namespace std;
// Точка входа в программу - функция WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    std::cout << "Hello, World!" << std::endl;
    EditorFrame editor_frame(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    editor_frame.CloseWindow();
    return 0;
}