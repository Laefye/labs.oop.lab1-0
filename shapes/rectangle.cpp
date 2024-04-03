#include "rectangle.h"

Rectangle::Rectangle(std::string& name, const Point& leftTop, const Point& rightBottom) : Shape(name)
{
    this->leftTop = leftTop;
    this->rightBottom = rightBottom;
    if (this->rightBottom.x <= this->leftTop.x || this->rightBottom.y >= this->leftTop.y) {
        throw IncorrectRectanglePointException("right bottom");
    }
}

double Rectangle::getArea() {
    double width = this->rightBottom.x - this->leftTop.x;
    double height = this->leftTop.y - this->rightBottom.y;
    return width * height;
}

void Rectangle::outputParams(std::string& output) {
    Shape::outputParams(output);
    output += " left top: " + this->leftTop.toString() + " right bottom: " + this->rightBottom.toString();
}
