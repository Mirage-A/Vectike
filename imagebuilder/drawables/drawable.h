#ifndef VECTIKE_DRAWABLE_H
#define VECTIKE_DRAWABLE_H

#include "../color.h"
#include "../transforms/transform.h"
#include <memory>

class Drawable{
public:
    //Получаем точку, возвращаем цвет этой точки если она принадлежит фигуре или прозрачный цвет иначе
    virtual Color GetPointColor(double x, double y) const = 0;
    //Выполняем параллельный перенос на вектор (dx, dy)
    virtual void Move(double dx, double dy) = 0;
    //Вращаем фигуру на угол angle против часовой стрелки относительно точки (center_x, center_y)
    virtual void Rotate(double angle, double center_x, double center_y) = 0;
    //Добавляем еще одно аффинное преобразование в список
    virtual void AddTransform(std::shared_ptr<Transform> transform) = 0;

};

#endif //VECTIKE_DRAWABLE_H
