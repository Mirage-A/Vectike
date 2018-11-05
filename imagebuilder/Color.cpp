struct Color {
    double alpha, r, g, b;

    Color(double alpha, double r, double g, double b) {
        this->alpha = alpha;
        this->r = r;
        this->g = g;
        this->b = b;
    }

    static Color EmptyColor() {
        // Возвращает прозрачный цвет
        Color c(0, 0, 0, 0);
        return c;
    }
};