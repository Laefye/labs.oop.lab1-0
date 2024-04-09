#ifndef IMPOSSIBLETRIANGLEEXCEPTION_H
#define IMPOSSIBLETRIANGLEEXCEPTION_H
#include <exception>


class ImpossibleTriangleException : public std::exception
{
public:
    ImpossibleTriangleException();
    const char* what() const noexcept override;
};

#endif // IMPOSSIBLETRIANGLEEXCEPTION_H
