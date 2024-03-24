#include "rectangle.h"

IncorrectRectanglePoint::IncorrectRectanglePoint(const std::string& point) {
    reason = "\""+ point + "\" has a incorrect position";
}

Rectangle::Rectangle(const Params& params) : Figure(params)
{
    params.get("left top", this->leftTop);
    params.get("right bottom", this->rightBottom);
    if (this->rightBottom.x <= this->leftTop.x || this->rightBottom.y >= this->leftTop.y) {
        throw IncorrectRectanglePoint("right bottom");
    }
}

double Rectangle::getArea() const {
    double width = this->rightBottom.x - this->leftTop.x;
    double height = this->leftTop.y - this->rightBottom.y;
    return width * height;
}
