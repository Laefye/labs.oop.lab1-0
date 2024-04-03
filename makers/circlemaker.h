#ifndef CIRCLEMAKER_H
#define CIRCLEMAKER_H
#include "maker.h"
#include "shapes/circle.h"
#include "exceptions/incorrectinputexception.h"

class CircleMaker : public Maker
{
public:
    CircleMaker();

    Shape* make() override;
};

#endif // CIRCLEMAKER_H
