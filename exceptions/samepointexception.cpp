#include "samepointexception.h"

SamePointException::SamePointException(int onePoint, int otherPoint)
{
    this->whatString = std::to_string(onePoint) + " and " + std::to_string(otherPoint) + " has same coordinate";
}

const char* SamePointException::what() const noexcept {
    return this->whatString.c_str();
}
