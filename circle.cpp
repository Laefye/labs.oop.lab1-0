#include "circle.h"
#include <iostream>
#include <cmath>

CircleFactory::CircleFactory() : Factory("Circle") {

}

void CircleFactory::create(Figure*& output) {
    output = new Circle();
}

Circle::Circle() {
    std::cout << "Radius: ";
    if (!(std::cin >> this->radius) || this->radius <= 0) {
        throw InputException("Radius is incorrect");
    };
    std::cout << "Center (x, y): ";
    if (!(std::cin >> this->center.x >> this->center.y)) {
        throw InputException("Center is incorrect");
    }
}

std::string Circle::getParameters() {
    return Figure::getParameters() + " Radius: " + std::to_string(radius) + " Center: " + center.toString();
}

float Circle::getArea() {
    return M_PI * radius * radius;
}
