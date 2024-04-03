#ifndef SHAPE_H
#define SHAPE_H
#include <string>


class Shape
{
private:
    std::string name;
public:
    Shape(const std::string& name);
    virtual ~Shape() = default;

    virtual double getArea() = 0;
    virtual void outputParams(std::string& params);
};

#endif // SHAPE_H
