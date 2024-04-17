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

std::string Circle::getParams() {
    return "Circle " + Figure::getParams() + " center: " + this->center.toString() + " radius: " + std::to_string(this->radius);
}
