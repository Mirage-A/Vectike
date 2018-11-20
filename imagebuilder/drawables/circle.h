#ifndef VECTIKE_CIRCLE_H
#define VECTIKE_CIRCLE_H

#include "drawable.h"

class Circle : public Drawable {
protected:
    Color color_ = Color::EmptyColor();
    double radius_;
    double width_;
public:
    Circle(double radius, double width, Color color) :
        radius_(radius), width_(width), color_(color) {};

    Circle(double x, double y, double radius, double width, Color color) :
        Circle(radius, width, color) {
        transforms_.push_back(std::shared_ptr<Transform>(new MoveTransform(x, y)));
    }

    virtual Color GetPointColor(double x, double y) const override;
};

#endif //VECTIKE_CIRCLE_H
