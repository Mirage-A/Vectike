#ifndef VECTIKE_GROUP_H
#define VECTIKE_GROUP_H

#include "drawable.h"

//Группа, которая состоит из нескольких фигур. Преобразования можно совершать над всей группой сразу.
class Group : public Drawable {
protected:
    std::vector<std::shared_ptr<Drawable>> drawables_list_;
public:
    Group() {}

    Group(std::vector<std::shared_ptr<Drawable>> drawables_list) : drawables_list_(drawables_list) {}

    virtual Color GetPointColor(double x, double y) const override;

};

#endif //VECTIKE_GROUP_H
