#include "circlefactory.h"

CircleFactory::CircleFactory(const Params& params) : Factory("Circle", params) {

}

std::shared_ptr<Figure> CircleFactory::create() {
    return std::shared_ptr<Figure>(new Circle(this->getParams()));
}
