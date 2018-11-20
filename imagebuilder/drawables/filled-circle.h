#ifndef VECTIKE_FILLED_CIRCLE_H
#define VECTIKE_FILLED_CIRCLE_H

#include "drawable.h"

class FilledCircle : public Drawable {
protected:
    Color color_ = Color::EmptyColor();
    double radius_;
public:
    FilledCircle(double radius, Color color) :
            radius_(radius), color_(color) {};

    FilledCircle(double x, double y, double radius, Color color) :
            FilledCircle(radius, color) {
        transforms_.push_back(std::shared_ptr<Transform>(new MoveTransform(x, y)));
    }

    virtual Color GetPointColor(double x, double y) const override;
};

#endif //VECTIKE_FILLED_CIRCLE_H
