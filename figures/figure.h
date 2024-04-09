#ifndef FIGURE_H
#define FIGURE_H
#include <string>


class Figure
{
private:
    std::string name;
public:
    Figure(const std::string& name);
    virtual ~Figure() = default;

    virtual double getArea() = 0;
    virtual void outputParams(std::string& params);
};

#endif // FIGURE_H
