#ifndef VECTIKE_TRANSFORM_H
#define VECTIKE_TRANSFORM_H

#include <memory>
#include "../math/point.h"
#include "../math/math-utils.h"

class Transform {
public:
    //Возвращает точку, которая после данного преобразования перейдет в transformed_point
    //Т.е. в методе Image::Render() мы перебираем все точки, для каждой фигуры перебираем ее преобразования с конца
    //получаем точку, которой эта точка была до преобразования и вызываем GetOriginalPoint для предыдущего
    //преобразования уже от полученной точки, в итоге будет легко проверить принадлежность точки фигуре
    //(можно привести все к стандартному виду, например, к единичному вектору/единичной окружности/etc)
    virtual Point GetOriginalPoint(Point transformed_point) const = 0;
};


#endif //VECTIKE_TRANSFORM_H
