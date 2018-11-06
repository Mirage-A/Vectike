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
    return 0;
}