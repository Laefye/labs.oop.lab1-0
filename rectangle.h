#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

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

#endif // RECTANGLE_H
