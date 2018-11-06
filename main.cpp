#include <iostream>
#include <vector>
#include "editor/editor-frame.h"
#include <windows.h>
using namespace std;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    std::cout << "Hello, World!" << std::endl;
    EditorFrame myEditor;
    myEditor.WindowCreation(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
    for(int i = 10; i < 20; ++i) {
        for(int k = 10; k < 20; ++k) {
            myEditor.DrawPixel(i, k, 255, 0, 0);
        }
    }
    myEditor.CloseWindow();
    return 0;
}