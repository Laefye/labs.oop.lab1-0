#ifndef INCORRECTRADIUSEXCEPTION_H
#define INCORRECTRADIUSEXCEPTION_H
#include <exception>


class IncorrectRadiusException : public std::exception
{
public:
    IncorrectRadiusException();

    const char* what() const noexcept override;
};

#endif // INCORRECTRADIUSEXCEPTION_H
