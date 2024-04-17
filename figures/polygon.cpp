#include "polygon.h"
#include <iostream>

Polygon::Polygon(const std::string& name, const std::vector<Point> points) : Figure(name), points(points) {
    if (points.size() < 3) {
        throw ImpossiblePolygonException();
    }
    for (size_t i = 0; i < points.capacity(); i++) {
        for (size_t j = i + 1; j < points.capacity(); j++) {
            if (points[i].x == points[j].x && points[i].y == points[j].y) {
                throw SamePointException(i + 1, j + 1);
            }
        }
    }
    graham();
}

bool sort(const Point& a, const Point& b) {
    bool result = false;
    if ((a.x == 0 && a.y == 0) || (b.x == 0 && b.y == 0)) {
        result = (a.x == 0 && a.y == 0);
    }
    return result || atan2(a.y, a.x) < atan2(b.y, b.x);
}

void Polygon::graham() {
    Point base = getLeftBottomPoint();
    std::vector<Point> relativePoints{points};
    for (size_t i = 0; i < relativePoints.capacity(); i++) {
        relativePoints[i].x -= base.x;
        relativePoints[i].y -= base.y;
    }
    std::sort(relativePoints.begin(), relativePoints.end(), sort);
    std::list<Point> stack;
    stack.push_back(relativePoints[0]);
    stack.push_back(relativePoints[1]);
    for (size_t i = 2; i < relativePoints.capacity(); i++) {
        Point nextToTop = *(--(--stack.end()));
        Point top = *(--stack.end());
        Point point = relativePoints[i];
        while ((top.x - nextToTop.x) * (point.y - top.y) - (top.y - nextToTop.y) * (point.x - top.x) < 0) {
            stack.pop_back();

            nextToTop = *(--(--stack.end()));
            top = *(--stack.end());
        }
        stack.push_back(point);
    }
    if (stack.size() != relativePoints.size()) {
        throw ImpossiblePolygonException();
    }
    for (size_t i = 0; i < relativePoints.capacity(); i++) {
        points[i].x = relativePoints[i].x + base.x;
        points[i].y = relativePoints[i].y + base.y;
    }
}

Point& Polygon::getLeftBottomPoint() {
    Point* point = &points[0];
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].x > point->x) {
            continue;
        }
        if (points[i].x < point->x) {
            point = &points[i];
        } else if (points[i].y < point->y) {
            point = &points[i];
        }
    }
    return *point;
}

double Polygon::getArea() {
    double sub = 0;
    for (size_t i = 0; i < points.capacity() - 1; i++) {
        sub += (points[i].x + points[i+1].x)*(points[i].y - points[i+1].y);
    }
    sub += (points[points.capacity() - 1].x + points[0].x)*(points[points.capacity() - 1].y - points[0].y);
    return std::fabs(sub) / 2;
}

std::string Polygon::getParams() {
    std::string params = "Polygon " + Figure::getParams();
    for (size_t i = 0; i < points.capacity(); i++) {
        params += " " + std::to_string(i+1) + ": " + points[i].toString();
    }
    return params;
}

