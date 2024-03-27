#include "figure.h"

Figure::Figure(const Params& params)
{
    params.get("name", this->name);
}

const std::string& Figure::getName() const {
    return this->name;
}

std::string Figure::getParams() const {
    return "name: " + this->name;
}

