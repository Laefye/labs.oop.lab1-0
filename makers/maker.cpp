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

void Maker::read(const std::string& name, std::vector<Point>& vector) {
    std::cout << name << " count: ";
    size_t count;
    if (!(std::cin >> count)) {
        throw IncorrectInputException();
    }
    vector.resize(count);
    for (size_t i = 0; i < count; i++) {
        std::cout << name << " element " << i + 1 << ": ";
        if (!(std::cin >> vector[i].x >> vector[i].y)) {
            throw IncorrectInputException();
        }
    }
}
