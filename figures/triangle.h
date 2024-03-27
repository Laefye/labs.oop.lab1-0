#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"
#include "exceptions/samecoordinate.h"

class Triangle : public Figure
{
private:
    Point points[3];

    double getDistance(const Point& start, const Point& end) const;
public:
    Triangle(const Params& params);

    double getArea() const override;
};

#endif // TRIANGLE_H
