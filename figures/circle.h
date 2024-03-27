#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include "point.h"
#include "exceptions/incorrectcircleradius.h"

class Circle : public Figure
{
private:
    Point center;
    double radius;
public:
    Circle(const Params& params);

    std::string getParams() const override;
    double getArea() const override;
};

#endif // CIRCLE_H
