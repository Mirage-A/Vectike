#ifndef FOO_C_INCLUDED /* any name uniquely mapped to file name */
#define FOO_C_INCLUDED

#include "Drawable.cpp"
//class Drawable;

class Transform {
    void ApplyTo(Drawable drawable);
};

#endif