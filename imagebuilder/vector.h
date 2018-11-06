
#ifndef VECTIKE_VECTOR_H
#define VECTIKE_VECTOR_H

#include <vector>
#include "drawable.h"

class Vector : Drawable {
private:
    std::vector<Transform> transforms_;
public:
    //Получаем точку, возвращаем цвет этой точки или прозрачный цвет
    Color GetPointColor(double x, double y) const;
    void Move(double dx, double dy);
    void Rotate(double angle);
    void AddTransform(Transform transform);
};

#endif //VECTIKE_VECTOR_H
