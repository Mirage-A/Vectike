#ifndef VECTIKE_POLYGON_H
#define VECTIKE_POLYGON_H

#include "drawable.h"
#include "group.h"

class Polygon : public Group {
public:
    // Строит многоугольник по списку вершин
    Polygon(std::vector<Point> nodes, double width, Color color);
};

#endif //VECTIKE_POLYGON_H
