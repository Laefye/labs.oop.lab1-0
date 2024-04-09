#ifndef MAKER_H
#define MAKER_H
#include "figures/figure.h"
#include "figures/point.h"
#include "exceptions/incorrectinputexception.h"
#include <string>
#include <vector>
#include "figures/point.h"

class Maker
{
private:
    std::string name;
protected:
    void read(const std::string& name, Point& point);
    void read(const std::string& name, double& number);
    void read(const std::string& name, std::string& str);
    void read(const std::string& name, std::vector<Point>& vector);
public:
    Maker(const std::string& name);
    virtual ~Maker() = default;

    std::string getName() const;

    virtual Figure* make() = 0;
};

#endif // MAKER_H
