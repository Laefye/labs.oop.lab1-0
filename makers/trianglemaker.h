#ifndef TRIANGLEMAKER_H
#define TRIANGLEMAKER_H
#include "maker.h"
#include "figures/triangle.h"


class TriangleMaker : public Maker
{
public:
    TriangleMaker();

    Figure* make() override;
};

#endif // TRIANGLEMAKER_H
