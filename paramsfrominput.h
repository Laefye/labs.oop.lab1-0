#ifndef PARAMSFROMINPUT_H
#define PARAMSFROMINPUT_H
#include <string>
#include "params.h"
#include "point.h"


class ParamsFromInput : public Params
{
public:
    void get(const std::string& key, std::string& output) const override;
    void get(const std::string& key, double& output) const override;
    void get(const std::string& key, Point& output) const override;
};

#endif // PARAMSFROMINPUT_H
