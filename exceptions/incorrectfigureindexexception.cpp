#include "incorrectfigureindexexception.h"

IncorrectFigureIndexException::IncorrectFigureIndexException()
{

}

const char* IncorrectFigureIndexException::what() const noexcept {
    return "Figure index is incorrect";
}
