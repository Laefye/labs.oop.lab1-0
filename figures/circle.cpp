#include "circle.h"
#include <cmath>

Circle::Circle(const std::string& name, const Point& center, double radius) : Figure(name) {
    this->center = center;
    if (radius <= 0) {
        throw IncorrectRadiusException();
    }
    this->radius = radius;
}

double Circle::getArea() {
    return M_PI * this->radius * this->radius;
}

void Circle::outputParams(std::string& output) {
    Figure::outputParams(output);
    output += " center: " + this->center.toString() + " radius: " + std::to_string(this->radius);
}
