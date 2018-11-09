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
    EditorFrame myEditor;
    myEditor.WindowCreation(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
    double wSize = 200,hSize = 100;
    Color myColor(0, 0, 0 , 0);
    Image myImage = ImageBuilder::CreateImage("",wSize,hSize);
    for(int i = 0; i < wSize; ++i) {
        for(int k = 0; k < hSize; ++k) {
            myColor = myImage.GetPixelColor(i, k);
            myEditor.DrawPixel(i, k, myColor.GetRed(),myColor.GetGreen(),myColor.GetBlue());
        }
    }
    myEditor.CloseWindow();
    return 0;
}