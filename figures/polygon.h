#ifndef POLYGON_H
#define POLYGON_H
#include "figure.h"
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include "point.h"
#include "exceptions/impossiblepolygonexception.h"
#include "exceptions/samepointexception.h"

class Polygon : public Figure
{
private:
    std::vector<Point> points;

    void graham();
    Point& getLeftBottomPoint();
public:
    Polygon(const std::string& name, const std::vector<Point> points);

    double getArea() override;
    void outputParams(std::string& params) override;
};

#endif // POLYGON_H
