#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "figure.h"
#include "exceptions/samepointexception.h"

class Triangle : public Figure
{
private:
    Point points[3];
    double getDistance(const Point& start, const Point& end) const;
public:
    Triangle(const std::string& name, const Point& first, const Point& second, const Point& third);

    double getArea() override;
    void outputParams(std::string &params) override;
};

#endif // TRIANGLE_H
