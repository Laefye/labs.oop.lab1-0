#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include "point.h"

class IncorrectCircleRadius : public BadParams {
public:
    IncorrectCircleRadius();
};

class Circle : public Figure
{
private:
    Point center;
    double radius;
public:
    Circle(const Params& params);

    double getArea() const override;
};

#endif // CIRCLE_H
