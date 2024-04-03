#include "incorrectradiusexception.h"

IncorrectRadiusException::IncorrectRadiusException()
{

}

const char* IncorrectRadiusException::what() const noexcept {
    return "Radius must be positive number";
}
