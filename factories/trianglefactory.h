#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "factory.h"
#include "../figures/triangle.h"


class TriangleFactory : public Factory {
public:
    TriangleFactory(const Params& params);

    std::shared_ptr<Figure> create() override;
};


#endif // TRIANGLEFACTORY_H
