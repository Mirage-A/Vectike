
#ifndef VECTIKE_VECTOR_H
#define VECTIKE_VECTOR_H

#include <vector>
#include "drawable.h"

class Vector : public Drawable {
private:
    std::vector<std::shared_ptr<Transform>> transforms_;
    Color color_ = Color::EmptyColor();
    double x1_, y1_, x2_, y2_;
    double width_;
public:
    Vector(double x1, double y1, double x2, double y2, double width, Color color);

    //Получаем точку, возвращаем цвет этой точки если она принадлежит фигуре или прозрачный цвет иначе
    virtual Color GetPointColor(double x, double y) const override;
    //Выполняем параллельный перенос на вектор (dx, dy)
    virtual void Move(double dx, double dy) override;
    //Вращаем фигуру на угол angle против часовой стрелки относительно точки (center_x, center_y)
    virtual void Rotate(double angle, double center_x, double center_y) override;
    //Добавляем еще одно аффинное преобразование в список
    virtual void AddTransform(std::shared_ptr<Transform> transform) override;
};

#endif //VECTIKE_VECTOR_H
