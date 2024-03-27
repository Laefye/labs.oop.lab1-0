#ifndef POINT_H
#define POINT_H
#include "string"

struct Point {
    double x;
    double y;

    std::string toString() const;
};

#endif // POINT_H
