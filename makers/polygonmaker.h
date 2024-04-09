#ifndef POLYGONMAKER_H
#define POLYGONMAKER_H
#include "maker.h"
#include "figures/polygon.h"


class PolygonMaker : public Maker
{
public:
    PolygonMaker();

    Figure* make() override;
};

#endif // POLYGONMAKER_H
