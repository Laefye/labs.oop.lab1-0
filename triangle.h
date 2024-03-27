#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include "factory.h"

class SameCoordinate : public BadParams {
public:
    SameCoordinate();
};

class Triangle : public Figure
{
private:
    Point points[3];

    double getDistance(const Point& start, const Point& end) const;
public:
    Triangle(const Params& params);

    double getArea() const override;
};


class TriangleFactory : public Factory {
public:
    TriangleFactory(const Params& params);

    std::shared_ptr<Figure> create() override;
};


#endif // TRIANGLE_H
