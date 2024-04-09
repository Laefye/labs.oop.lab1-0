#include "circlemaker.h"

CircleMaker::CircleMaker() : Maker("Circle") {

}

Figure* CircleMaker::make() {
    std::string name;
    Point center;
    double radius;
    this->read("Name", name);
    this->read("Center", center);
    this->read("Radius", radius);
    return new Circle(name, center, radius);
}
