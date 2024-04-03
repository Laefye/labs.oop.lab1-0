#ifndef TRIANGLEMAKER_H
#define TRIANGLEMAKER_H
#include "maker.h"
#include "shapes/triangle.h"


class TriangleMaker : public Maker
{
public:
    TriangleMaker();

    Shape* make() override;
};

#endif // TRIANGLEMAKER_H
