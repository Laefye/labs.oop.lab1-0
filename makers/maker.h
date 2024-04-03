#ifndef MAKER_H
#define MAKER_H
#include "shapes/shape.h"
#include "shapes/point.h"
#include "exceptions/incorrectinputexception.h"
#include <string>

class Maker
{
private:
    std::string name;
protected:
    void read(const std::string& name, Point& point);
    void read(const std::string& name, double& number);
    void read(const std::string& name, std::string& str);
public:
    Maker(const std::string& name);
    virtual ~Maker() = default;

    std::string getName() const;

    virtual Shape* make() = 0;
};

#endif // MAKER_H
