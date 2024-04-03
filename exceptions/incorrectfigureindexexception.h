#ifndef INCORRECTFIGUREINDEXEXCEPTION_H
#define INCORRECTFIGUREINDEXEXCEPTION_H
#include <exception>


class IncorrectFigureIndexException : public std::exception
{
public:
    IncorrectFigureIndexException();

    const char* what() const noexcept override;
};

#endif // INCORRECTFIGUREINDEXEXCEPTION_H
