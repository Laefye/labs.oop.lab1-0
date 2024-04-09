#ifndef IMPOSSIBLEPOLYGONEXCEPTION_H
#define IMPOSSIBLEPOLYGONEXCEPTION_H
#include <exception>


class ImpossiblePolygonException : public std::exception
{
public:
    ImpossiblePolygonException();

    const char* what() const noexcept override;
};

#endif // IMPOSSIBLEPOLYGONEXCEPTION_H
