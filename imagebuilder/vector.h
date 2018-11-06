
#ifndef VECTIKE_VECTOR_H
#define VECTIKE_VECTOR_H

#include <vector>
#include "drawable.h"

class Vector : public Drawable {
private:
    std::vector<Transform> transforms_;
    Color color_ = Color::EmptyColor();
    double x1_, y1_, x2_, y2_;
    double width_;
public:
    Vector(double x1, double y1, double x2, double y2, double width, Color color);

    //Получаем точку, возвращаем цвет этой точки или прозрачный цвет
    Color GetPointColor(double x, double y) const;
    void Move(double dx, double dy);
    void Rotate(double angle, double center_x, double center_y);
    void AddTransform(Transform transform);
};

#endif //VECTIKE_VECTOR_H
