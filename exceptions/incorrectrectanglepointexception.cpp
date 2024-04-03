#include "incorrectrectanglepointexception.h"

IncorrectRectanglePointException::IncorrectRectanglePointException(const std::string& pointName)
{
    this->whatText = "The " + pointName + " point is incorrect";
}

const char* IncorrectRectanglePointException::what() const noexcept {
    return this->whatText.c_str();
}
