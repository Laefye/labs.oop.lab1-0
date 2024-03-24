#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class IncorrectRectanglePoint : public BadParams {
public:
    IncorrectRectanglePoint(const std::string& point);
};

class Rectangle : public Figure
{
private:
    Point leftTop;
    Point rightBottom;
public:
    Rectangle(const Params& params);

    double getArea() const override;
};

#endif // RECTANGLE_H
