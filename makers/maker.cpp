#include "maker.h"
#include <iostream>

Maker::Maker(const std::string& name)
{
    this->name = name;
}

std::string Maker::getName() const {
    return this->name;
}

void Maker::read(const std::string& name, Point& point) {
    std::cout << name << ": ";
    if (!(std::cin >> point.x >> point.y)) {
        throw IncorrectInputException();
    }
}

void Maker::read(const std::string& name, double& number) {
    std::cout << name << ": ";
    if (!(std::cin >> number)) {
        throw IncorrectInputException();
    }
}

void Maker::read(const std::string& name, std::string& str) {
    std::cout << name << ": ";
    if (!(std::cin >> str)) {
        throw IncorrectInputException();
    }
}
