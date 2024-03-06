#ifndef FIGURES_H
#define FIGURES_H
#include <vector>
#include "figure.h"
#include "factory.h"
#include "circle.h"
#include "rectangle.h"

class Figures
{
private:
    std::vector<Factory*> factories;
public:
    Figures();
    ~Figures();

    void show();

    void create(int indexFactory, Figure*& output);
};

#endif // FIGURES_H
