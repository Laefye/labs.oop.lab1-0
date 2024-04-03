#ifndef INCORRECTINPUTEXCEPTION_H
#define INCORRECTINPUTEXCEPTION_H
#include <string>
#include <exception>

class IncorrectInputException : public std::exception
{
public:
    IncorrectInputException();

    const char* what() const noexcept override;
};

#endif // INCORRECTINPUTEXCEPTION_H
