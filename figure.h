#ifndef FIGURE_H
#define FIGURE_H
#include "params.h"

class Figure
{
private:
    std::string name;
public:
    Figure(const Params& params);

    virtual double getArea() const = 0;
};

#endif // FIGURE_H
