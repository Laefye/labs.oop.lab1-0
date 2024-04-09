#include "impossibletriangleexception.h"

ImpossibleTriangleException::ImpossibleTriangleException()
{

}

const char* ImpossibleTriangleException::what() const noexcept {
    return "Impossible triangle";
}
