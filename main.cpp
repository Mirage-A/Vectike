#include <iostream>
#include <vector>
#include "editor/editor-frame.h"
#include <windows.h>
using namespace std;
// Точка входа в программу - функция WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    std::cout << "Hello, World!" << std::endl;
    EditorFrame editor_frame(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    editor_frame.CloseWindow();
    return 0;
}