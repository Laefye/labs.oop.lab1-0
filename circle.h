#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
#include "factory.h"

class Circle : public Figure {
private:
    float radius;
    Point center;
public:
    Circle();

    float getArea() override;

    std::string getParameters() override;
};

class CircleFactory : public Factory {
public:
    CircleFactory();

    void create(Figure*& output) override;
};

#endif // CIRCLE_H
