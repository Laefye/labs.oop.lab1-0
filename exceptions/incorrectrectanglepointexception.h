#ifndef INCORRECTRECTANGLEPOINTEXCEPTION_H
#define INCORRECTRECTANGLEPOINTEXCEPTION_H
#include <exception>
#include <string>

class IncorrectRectanglePointException : public std::exception
{
private:
    std::string whatText;
public:
    IncorrectRectanglePointException(const std::string& pointName);

    const char* what() const noexcept override;
};

#endif // INCORRECTRECTANGLEPOINTEXCEPTION_H
