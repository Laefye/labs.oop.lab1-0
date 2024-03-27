#include "trianglefactory.h"

TriangleFactory::TriangleFactory(const Params& params) : Factory("Triangle", params) {

}

std::shared_ptr<Figure> TriangleFactory::create() {
    return std::shared_ptr<Figure>(new Triangle(this->getParams()));
}
