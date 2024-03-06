#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure {
private:
    float radius;
    Point center;
public:
    Circle();

    float getArea() override;

    std::string getParameters() override;
};

#endif // CIRCLE_H
