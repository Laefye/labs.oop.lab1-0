#ifndef PARAMS_H
#define PARAMS_H
#include <string>
#include "figures/point.h"

class Params
{
public:
    virtual void get(const std::string& key, std::string& output) const = 0;
    virtual void get(const std::string& key, double& output) const = 0;
    virtual void get(const std::string& key, Point& output) const = 0;

    virtual ~Params() = default;
};

#endif // PARAMS_H
