//
// Created by Егор on 21.11.2018.
//

#ifndef VECTIKE_CONVEX_POLYGON_H
#define VECTIKE_CONVEX_POLYGON_H

#include "polygon.h"

class ConvexPolygon : Drawable {
protected:
    void SortNodes();
    virtual bool ContainsPoint(Point p) const;
public:
    std::vector<Point> nodes_;
    // Строит многоугольк по списку вершин
    // Если sorted == 1, то подразумевается, что вершины уже отсортированы
    // (обход против часовой стрелки)
    // Если sorted == 0, то вызывается метод SortNodes
    ConvexPolygon(std::vector<Point> nodes, Color color, bool sorted);

    // Тут метод SortNodes вызывается всегда
    ConvexPolygon(std::vector<Point> nodes, Color color) :
        ConvexPolygon(nodes, color, 0) {};

    //Получаем точку, возвращаем цвет этой точки если она принадлежит фигуре или прозрачный цвет иначе
    virtual Color GetPointColor(double x, double y) const override;
};
#endif //VECTIKE_CONVEX_POLYGON_H
