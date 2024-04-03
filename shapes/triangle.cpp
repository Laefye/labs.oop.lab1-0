#include "triangle.h"
#include "cmath"

Triangle::Triangle(const std::string& name, const Point& first, const Point& second, const Point& third) : Shape(name)
{
    this->points[0] = first;
    this->points[1] = second;
    this->points[2] = third;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = i + 1; j < 3; j++) {
            if (this->points[i].x == this->points[j].x && this->points[i].y == this->points[j].y) {
                throw SamePointException(i+1, j+1);
            }
        }
    }
}

double Triangle::getDistance(const Point &start, const Point &end) const {
    Point vector = {.x = end.x - start.x, .y = end.y - start.y};
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

double Triangle::getArea() {
    double first = this->getDistance(this->points[0], this->points[1]);
    double second = this->getDistance(this->points[1], this->points[2]);
    double third = this->getDistance(this->points[0], this->points[2]);
    double halfPerimetr = (first + second + third) / 2;
    return sqrt(halfPerimetr * (halfPerimetr - first) * (halfPerimetr - second) * (halfPerimetr - third));
}

void Triangle::outputParams(std::string& output) {
    Shape::outputParams(output);
    output += " first: " + this->points[0].toString() + " second: " + this->points[1].toString() + " third: " + this->points[2].toString();
}
