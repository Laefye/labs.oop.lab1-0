#include "figure.h"
#include <iostream>

std::string Point::toString() {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

InputException::InputException(const char* reason) {
    this->reason = reason;
}

const char* InputException::what() const noexcept {
    return this->reason;
}

Figure::Figure() {
    std::cout << "Name: ";
    if (!(std::cin >> name)) {
        throw InputException("Name is incorrect");
    };
}

Figure::~Figure() {

}

float Figure::getArea() {
    return 0;
}

std::string Figure::getParameters() {
    return name;
}

std::string Figure::getFigureName()  {
    return "TODO";
}
