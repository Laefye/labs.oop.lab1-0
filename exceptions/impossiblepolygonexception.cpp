#include "impossiblepolygonexception.h"

ImpossiblePolygonException::ImpossiblePolygonException()
{

}

const char* ImpossiblePolygonException::what() const noexcept {
    return "Impossible polygon";
}
