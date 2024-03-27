#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "factory.h"
#include "../figures/rectangle.h"


class RectangleFactory : public Factory {
public:
    RectangleFactory(const Params& params);

    std::shared_ptr<Figure> create() override;
};
#endif // RECTANGLEFACTORY_H
