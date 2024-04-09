#include "figure.h"

Figure::Figure(const std::string& name)
{
    this->name = name;
}

void Figure::outputParams(std::string& output) {
    output = "name: " + this->name;
}
