#include "triangle.h"
#include "cmath"

Triangle::Triangle(const std::string& name, const Point& first, const Point& second, const Point& third) : Figure(name)
{
    this->first = first;
    this->second = second;
    this->third = third;

    if (checkEquals(first, second)) {
        throw SamePointException(1, 2);
    }
    if (checkEquals(second, third)) {
        throw SamePointException(2, 3);
    }
    if (checkEquals(first, third)) {
        throw SamePointException(1, 3);
    }

    double firstLength = this->getDistance(this->first, this->second);
    double secondLength = this->getDistance(this->second, this->third);
    double thirdLength = this->getDistance(this->first, this->third);
    double max = std::fmax(firstLength, std::fmax(secondLength, thirdLength));
    double min = std::fmin(firstLength, std::fmin(secondLength, thirdLength));
    double middle = firstLength + secondLength + thirdLength - max - min;
    if (max >= min + middle) {
        throw ImpossibleTriangleException();
    }
}

bool Triangle::checkEquals(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

double Triangle::getDistance(const Point &start, const Point &end) const {
    Point vector = {.x = end.x - start.x, .y = end.y - start.y};
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

double Triangle::getArea() {
    double first = this->getDistance(this->first, this->second);
    double second = this->getDistance(this->second, this->third);
    double third = this->getDistance(this->first, this->third);
    double halfPerimetr = (first + second + third) / 2;
    return sqrt(halfPerimetr * (halfPerimetr - first) * (halfPerimetr - second) * (halfPerimetr - third));
}

void Triangle::outputParams(std::string& output) {
    Figure::outputParams(output);
    output += " first: " + this->first.toString() + " second: " + this->second.toString() + " third: " + this->third.toString();
}
