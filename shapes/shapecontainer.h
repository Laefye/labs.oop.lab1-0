#ifndef SHAPECONTAINER_H
#define SHAPECONTAINER_H
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "exceptions/incorrectfigureindexexception.h"
#include <vector>
#include <algorithm>

class ShapeCotainer
{
private:
    std::vector<Shape*> figures;
public:
    ShapeCotainer();
    ~ShapeCotainer();

    void add(Shape* figure);

    const std::vector<Shape*>& getVector();
    std::string getType(Shape* figure) const;
    double sumAreas() const;
    void sort();
    void remove(size_t index);
    void removeBiggerArea(double area);
};
#endif // SHAPECONTAINER_H
