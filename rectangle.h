#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include "factory.h"

class Rectangle : public Figure
{
private:
    Point leftTop;
    Point rightBottom;
public:
    Rectangle();

    float getArea() override;

    std::string getParameters() override;
};

class RectangleFactory : public Factory {
public:
    RectangleFactory();

    void create(Figure*& output) override;
};

#endif // RECTANGLE_H
