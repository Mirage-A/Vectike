
#ifndef VECTIKE_COLOR_H
#define VECTIKE_COLOR_H

class Color {
private:
    double alpha_, r_, g_, b_;
public:
    Color(double alpha, double r, double g, double b);

    //TODO Рисует цвет new_color поверх этого, возвращает новый цвет - результат
    Color CombineWith(Color new_color) const;

    // Возвращает прозрачный цвет
    static Color EmptyColor();
    static Color Black();
    static Color White();
    static Color Red();
    static Color Green();
    static Color Blue();
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getAlpha() const;
};

#endif //VECTIKE_COLOR_H
