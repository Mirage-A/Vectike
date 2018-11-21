#include "polygon.h"
#include "rounded-vector.h"


Polygon::Polygon(std::vector<Point> nodes, double width, Color color) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        drawables_list_.push_back(std::shared_ptr<Drawable>(new RoundedVector(
                nodes[i].x, nodes[i].y, nodes[(i+1) % nodes.size()].x, nodes[(i+1) % nodes.size()].y, width, color
                )));
    }
}
