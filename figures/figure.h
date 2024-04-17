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
    virtual std::string getParams();
};

#endif // FIGURE_H
