#include "rectanglefactory.h"

RectangleFactory::RectangleFactory(const Params& params) : Factory("Rectangle", params) {

}

std::shared_ptr<Figure> RectangleFactory::create() {
    return std::shared_ptr<Figure>(new Rectangle(this->getParams()));
}
