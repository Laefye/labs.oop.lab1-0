#ifndef CIRCLEFACTORY_H
#define CIRCLEFACTORY_H
#include "factory.h"
#include "../figures/circle.h"


class CircleFactory : public Factory {
public:
    CircleFactory(const Params& params);

    std::shared_ptr<Figure> create() override;
};

#endif // CIRCLEFACTORY_H
