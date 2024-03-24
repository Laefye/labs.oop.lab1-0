#include "circle.h"
#include <cmath>

IncorrectCircleRadius::IncorrectCircleRadius() {
    reason = "Radius can't be non positive";
}

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
