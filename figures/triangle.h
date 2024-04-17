#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "figure.h"
#include "exceptions/samepointexception.h"
#include "exceptions/impossibletriangleexception.h"

class Triangle : public Figure
{
private:
    Point first;
    Point second;
    Point third;
    double getDistance(const Point& start, const Point& end) const;
    bool checkEquals(const Point& a, const Point& b);
public:
    Triangle(const std::string& name, const Point& first, const Point& second, const Point& third);

    double getArea() override;
    std::string getParams() override;
};

#endif // TRIANGLE_H
