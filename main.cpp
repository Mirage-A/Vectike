#include <iostream>
#include <vector>
#include "editor/editor-frame.h"
#include <windows.h>
#include "imagebuilder/image-builder.h"
#include "imagebuilder/image.h"
using namespace std;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    std::cout << "Hello, World!" << std::endl;
    EditorFrame myEditor(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    myEditor.CloseWindow();
    return 0;
}