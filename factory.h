#ifndef FACTORY_H
#define FACTORY_H
#include "figure.h"
#include "memory"


class Factory
{
private:
    const Params& params;
    const std::string name;
protected:
    const Params& getParams();
public:
    Factory(const std::string& name, const Params& params);
    virtual std::shared_ptr<Figure> create() = 0;
    const std::string& getName();
};

#endif // FACTORY_H
