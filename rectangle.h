#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include "factory.h"

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

class RectangleFactory : public Factory {
public:
    RectangleFactory(const Params& params);

    std::shared_ptr<Figure> create() override;
};

#endif // RECTANGLE_H
