#ifndef RECTANGLEMAKER_H
#define RECTANGLEMAKER_H
#include "shapes/rectangle.h"
#include "maker.h"


class RectangleMaker : public Maker
{
public:
    RectangleMaker();

    Shape* make() override;
};

#endif // RECTANGLEMAKER_H
