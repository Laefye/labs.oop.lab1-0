#ifndef CIRCLEMAKER_H
#define CIRCLEMAKER_H
#include "maker.h"
#include "figures/circle.h"
#include "exceptions/incorrectinputexception.h"

class CircleMaker : public Maker
{
public:
    CircleMaker();

    Figure* make() override;
};

#endif // CIRCLEMAKER_H
