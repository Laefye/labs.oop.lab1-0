#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include "point.h"
#include "exceptions/incorrectradiusexception.h"

class Circle : public Figure
{
private:
    double radius;
    Point center;
public:
    Circle(const std::string& name, const Point& point, double radius);

    double getArea() override;
    void outputParams(std::string& output) override;
};

#endif // CIRCLE_H
