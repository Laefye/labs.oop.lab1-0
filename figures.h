#ifndef FIGURES_H
#define FIGURES_H
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <vector>
#include <memory>
#include <exception>

class ImpossibleCasting : public std::exception {
public:
    const char* what() const noexcept override;
};

class IncorrectFigureIndex : public std::exception {
public:
    const char* what() const noexcept override;
};

class Figures
{
private:
    std::vector<std::shared_ptr<Figure>> figures;
public:
    Figures();

    void add(const std::shared_ptr<Figure>& figure);

    const std::vector<std::shared_ptr<Figure>>& getVector();
    std::string getType(const std::shared_ptr<Figure>& figure) const;
    double sumAreas() const;
    void sort();
    void remove(size_t index);
    void removeBiggerArea(double area);
};

#endif // FIGURES_H
