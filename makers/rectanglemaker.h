#ifndef RECTANGLEMAKER_H
#define RECTANGLEMAKER_H
#include "figures/rectangle.h"
#include "maker.h"


class RectangleMaker : public Maker
{
public:
    RectangleMaker();

    Figure* make() override;
};

#endif // RECTANGLEMAKER_H
