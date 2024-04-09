#include "rectanglemaker.h"

RectangleMaker::RectangleMaker() : Maker("Rectangle")
{

}

Figure* RectangleMaker::make() {
    std::string name;
    Point leftTop;
    Point rightBottom;
    this->read("Name", name);
    this->read("Left Top", leftTop);
    this->read("Right Bottom", rightBottom);
    return new Rectangle(name, leftTop, rightBottom);
}
