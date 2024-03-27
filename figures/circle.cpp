#include "circle.h"
#include <cmath>

Circle::Circle(const Params& params) : Figure(params) {
    params.get("center", this->center);
    params.get("radius", this->radius);
    if (this->radius <= 0) {
        throw IncorrectCircleRadius();
    }
}

double Circle::getArea() const {
    return M_PI * this->radius * this->radius;
}

std::string Circle::getParams() const {
    return Figure::getParams() + " center: " + this->center.toString() + " radius: " + std::to_string(this->radius);
}
