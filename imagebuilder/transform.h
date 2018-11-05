//
// Created by Егор on 06.11.2018.
//

#ifndef VECTIKE_TRANSFORM_H
#define VECTIKE_TRANSFORM_H

//#include "drawable.h"



class Drawable;

class Transform {
    // Тут CLion выдаёт ошибку, хотя всё нормально компилится и работает
    virtual void ApplyTo(Drawable drawable);
};


#endif //VECTIKE_TRANSFORM_H
