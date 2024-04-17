#include "figure.h"

Figure::Figure(const std::string& name)
{
    this->name = name;
}

std::string Figure::getParams() {
    return "name: " + this->name;
}
