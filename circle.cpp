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

std::string Circle::getParams() const {
    return Figure::getParams() + " center: " + this->center.toString() + " radius: " + std::to_string(this->radius);
}

CircleFactory::CircleFactory(const Params& params) : Factory("Circle", params) {

}

std::shared_ptr<Figure> CircleFactory::create() {
    return std::shared_ptr<Figure>(new Circle(this->getParams()));
}
