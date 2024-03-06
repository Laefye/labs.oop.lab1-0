#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "figure.h"

class Factory {
    std::string name;
public:
    Factory(std::string name);
    virtual ~Factory();

    std::string getName();

    virtual void create(Figure*& output);
};

#endif // FACTORY_H
