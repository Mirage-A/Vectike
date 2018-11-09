// Включаем необходимый заголовочный файл для Windows-программ
#include <windows.h>
#include "editor-frame.h"
// Объявление функции окна (оконной процедуры)
HWND hWnd; // Уникальный идентификатор окна (handle)
HINSTANCE hInst; // Идентификатор приложения
HDC dc;
MSG msg; // Объявление структуры типа MSG, для работы с сообщениями
// Указатель на константную строку символов - имя программы и класса окна
LPCSTR AppName = "MyProgramm";
// Оконная процедура
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}
void EditorFrame::DrawPixel(int x, int y, int r, int g, int b) {
    SetPixel(dc, x, y, RGB(r, g, b));
}
// Точка входа в программу - функция WinMain
int WINAPI EditorFrame::WindowCreation(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
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

    // Стандартный цикл обработки сообщения
   // HBRUSH brush; // создаём кисть
    dc = GetDC(hWnd);
   // brush = CreateSolidBrush(RGB(0, 255, 0)); // CreateHatchBrush для штриховки
   // SelectObject(dc, brush); // выбираем кисть
    //Rectangle(dc, 0, 0, 30, 40); // рисуем прямоугольничек
   // MoveToEx(dc,20,20,0); // рисуем отрезок
   // LineTo(dc,56,69);
   // Ellipse(dc, 20, 80, 10, 56); // рисуем эллипс
   // POINT poly[3] = { {7,260 },{ 130 , 260 },{130/2, 200} }; // рисуем многоугольник по координатам вершин, которые храняться в poly
   // Polygon(dc, poly, 3);
    //while(GetMessage(&msg, NULL, 0, 0))
    //{
        //TranslateMessage(&msg);
        //DispatchMessage(&msg);
    //}
    //DeleteObject(brush); // удаляем кисть
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


