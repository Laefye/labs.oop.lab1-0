#include "factory.h"

Factory::Factory(const std::string& name, const Params& params) : params(params), name(name)
{

}

const Params& Factory::getParams() {
    return this->params;
}

const std::string& Factory::getName() {
    return this->name;
}
