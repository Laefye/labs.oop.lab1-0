#include "shape.h"

Shape::Shape(const std::string& name)
{
    this->name = name;
}

void Shape::outputParams(std::string& output) {
    output = "name: " + this->name;
}
