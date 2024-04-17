#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include "point.h"
#include "exceptions/incorrectrectanglepointexception.h"


class Rectangle : public Figure
{
private:
    Point leftTop;
    Point rightBottom;
public:
    Rectangle(std::string& name, const Point& leftTop, const Point& rightBottom);

    double getArea() override;
    std::string getParams() override;
};

#endif // RECTANGLE_H
