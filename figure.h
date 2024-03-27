#ifndef FIGURE_H
#define FIGURE_H
#include "params.h"

class Figure
{
private:
    std::string name;
public:
    Figure(const Params& params);

    const std::string& getName() const;

    virtual std::string getParams() const;

    virtual double getArea() const = 0;
};

#endif // FIGURE_H
