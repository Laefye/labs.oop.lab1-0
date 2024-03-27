#include "triangle.h"
#include <cmath>
#include <iostream>

SameCoordinate::SameCoordinate() {
    this->reason = "Some points has same coordintate";
}

Triangle::Triangle(const Params& params) : Figure(params)
{
    params.get("first point", this->points[0]);
    params.get("second point", this->points[1]);
    params.get("third point", this->points[2]);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = i + 1; j < 3; j++) {
            if (this->points[i].x == this->points[j].x && this->points[i].y == this->points[j].y) {
                throw SameCoordinate();
            }
        }
    }
}

double Triangle::getDistance(const Point &start, const Point &end) const {
    Point vector = {.x = end.x - start.x, .y = end.y - start.y};
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

double Triangle::getArea() const {
    double first = this->getDistance(this->points[0], this->points[1]);
    double second = this->getDistance(this->points[1], this->points[2]);
    double third = this->getDistance(this->points[0], this->points[2]);
    double halfPerimetr = (first + second + third) / 2;
    return sqrt(halfPerimetr * (halfPerimetr - first) * (halfPerimetr - second) * (halfPerimetr - third));
}

TriangleFactory::TriangleFactory(const Params& params) : Factory("Triangle", params) {

}

std::shared_ptr<Figure> TriangleFactory::create() {
    return std::shared_ptr<Figure>(new Triangle(this->getParams()));
}

