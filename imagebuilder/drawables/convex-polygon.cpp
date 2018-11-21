#include "convex-polygon.h"
#include <vector>
#include <algorithm>


struct Node {
    Point p;
    double angle;
    Node(Point p) : p(p), angle(MathUtils::GetAngle(p)) {};
};

bool Comparator(Node a, Node b) {
    return a.angle == b.angle ? MathUtils::GetRange(a.p) < MathUtils::GetRange(b.p) : a.angle < b.angle;
}

void ConvexPolygon::SortNodes() {
    std::sort(nodes_.begin(), nodes_.end(), Comparator);
}

bool ConvexPolygon::ContainsPoint(Point p) const {
    // TODO
    return 0;
}

ConvexPolygon::ConvexPolygon(std::vector<Point> nodes, Color color, bool sorted) {
    if (!sorted) {
        SortNodes();
    }
}

Color ConvexPolygon::GetPointColor(double x, double y) const {
    // TODO
    return Color::EmptyColor();
}