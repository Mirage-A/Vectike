#ifndef VECTIKE_DRAWABLE_H
#define VECTIKE_DRAWABLE_H

#include "../color.h"
#include "../transforms/move-transform.h"
#include "../transforms/rotate-transform.h"
#include <memory>
#include <vector>

class Drawable{
private:

protected:
    //Возвращаем точку, которая перейдет в данную после всех преобразований из transforms_
    Point GetOriginalPoint(Point transformed_point) const;
    Point GetOriginalPoint(double transformed_x, double transformed_y) const;

public:
    std::vector<std::shared_ptr<Transform>> transforms_;

    //Получаем точку, возвращаем цвет этой точки если она принадлежит фигуре или прозрачный цвет иначе
    virtual Color GetPointColor(double x, double y) const = 0;

    //Добавляем еще одно аффинное преобразование в список
    void AddTransform(std::shared_ptr<Transform> transform);

};

#endif //VECTIKE_DRAWABLE_H
