
#ifndef VECTIKE_VECTOR_H
#define VECTIKE_VECTOR_H

#include "drawable.h"

class Vector : public Drawable {
private:
    //Содержит ли вектор точку БЕЗ УЧЕТА ПРЕОБРАЗОВАНИЙ
    bool ContainsPoint(Point p) const;
protected:
    Color color_ = Color::EmptyColor();
    double length_;
    double width_;
public:
    Vector(double length, double width, Color color);
    Vector(double x1, double y1, double x2, double y2, double width, Color color);


    //Получаем точку, возвращаем цвет этой точки если она принадлежит фигуре или прозрачный цвет иначе
    virtual Color GetPointColor(double x, double y) const override;
    //Добавляем еще одно аффинное преобразование в список

};

#endif //VECTIKE_VECTOR_H
