// Включаем необходимый заголовочный файл для Windows-программ
#include <windows.h>
#include "editor-frame.h"
#include <iostream>
#include <winspool.h>
#include "../imagebuilder/image-builder.h"
#include "editor-logic.h"

EditorLogic EditorFrame::editor_logic;
HDC EditorFrame::dc;

EditorFrame::EditorFrame(HINSTANCE &hInstance, HINSTANCE &hPrevInstance,
                         LPSTR &lpCmdLine, int nCmdShow)
{

    WindowCreation(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
    //EditorFrame::editor_logic = EditorLogic();
    size_t wSize = 200,hSize = 200;
    Color myColor(0, 0, 0 , 0);
    Image myImage = ImageBuilder::CreateImage("",wSize,hSize);
    for(size_t i = 0; i < wSize; ++i) {
        for(size_t k = 0; k < hSize; ++k) {
            myColor = myImage.GetPixelColor(i, k);
            EditorFrame::editor_logic.DrawPixel(dc, i, k, myColor.GetRed(),myColor.GetGreen(),myColor.GetBlue());
        }
    }
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_SIZE:
            EditorFrame::editor_logic.ChangePictureSize(EditorFrame::dc, HIWORD(lParam), LOWORD(lParam));
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}
// Точка входа в программу - функция WinMain
int WINAPI EditorFrame::WindowCreation(HINSTANCE &hInstance, HINSTANCE &hPrevInstance,
                   LPSTR &lpCmdLine, int nCmdShow)
{

    hInst = hInstance; // Сохраняем идентификатор приложения

// Заполняем структуру WNDCLASS
    WNDCLASS wc;
    // Инициализируем выделенную для структуры память нулями
    ZeroMemory(&wc, sizeof(wc));
    //wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(hInst, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = AppName;

    RegisterClass(&wc); // Создаем и регистрируем оконный класс

// Создаем окно программы
    hWnd = CreateWindow(
            AppName, // Имя класса окна
            AppName, // Заголовок окна
            WS_OVERLAPPEDWINDOW, // Стиль окна
            CW_USEDEFAULT, 0, // Горизонтальная и вертикальная позиции окна
            300, 300, // Ширина и высота окна
            NULL, // Хендл родительского окна
            NULL, // Хендл меню
            hInst, // Идентификатор приложения
            NULL); // Дополнительные данные окна

    ShowWindow(hWnd, SW_SHOW); // Отображаем окно
    UpdateWindow(hWnd); // Перерисовываем окно
    EditorFrame::dc = GetDC(hWnd);
    return msg.wParam;
}
int WINAPI EditorFrame::CloseWindow() {
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}


