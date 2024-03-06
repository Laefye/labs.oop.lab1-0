#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle() {
    std::cout << "Left Top (x, y): ";
    if (!(std::cin >> this->leftTop.x >> this->leftTop.y)) {
        throw InputException("Left top coordinates is incorrect");
    }
    std::cout << "Right Bottom (x, y): ";
    if (!(std::cin >> this->rightBottom.x >> this->rightBottom.y) || this->rightBottom.x <= this->leftTop.x || this->rightBottom.y >= this->leftTop.y) {
        throw InputException("Right bottom coordinates is incorrect");
    }
}

float Rectangle::getArea() {
    float width = rightBottom.x - leftTop.x;
    float height = leftTop.y - rightBottom.y;
    return width * height;
}

std::string Rectangle::getParameters() {
    return Figure::getParameters() + " Left Top: " + leftTop.toString() + " Right Bottom: " + rightBottom.toString();
}
