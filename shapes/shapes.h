#ifndef SHAPES_H
#define SHAPES_H
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "exceptions/incorrectfigureindexexception.h"
#include <vector>
#include <algorithm>

class Shapes
{
private:
    std::vector<Shape*> figures;
public:
    Shapes();
    ~Shapes();

    void add(Shape* figure);

    const std::vector<Shape*>& getVector();
    std::string getType(Shape* figure) const;
    double sumAreas() const;
    void sort();
    void remove(size_t index);
    void removeBiggerArea(double area);
};
#endif // SHAPES_H
