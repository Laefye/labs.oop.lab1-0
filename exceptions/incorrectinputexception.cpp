#include "incorrectinputexception.h"

IncorrectInputException::IncorrectInputException()
{

}

const char* IncorrectInputException::what() const noexcept {
    return "Incorrect input";
}
