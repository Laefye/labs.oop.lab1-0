#ifndef figures_H
#define figures_H
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "polygon.h"
#include "exceptions/incorrectfigureindexexception.h"
#include <vector>
#include <algorithm>

class FigureContainer
{
private:
    std::vector<Figure*> figures;
public:
    FigureContainer();
    ~FigureContainer();

    void add(Figure* figure);

    const std::vector<Figure*>& getVector();
    double sumAreas() const;
    void sort();
    void remove(size_t index);
    void removeBiggerArea(double area);
};
#endif // figures_H
