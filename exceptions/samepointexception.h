#ifndef SAMEPOINTEXCEPTION_H
#define SAMEPOINTEXCEPTION_H
#include <exception>
#include <string>


class SamePointException : public std::exception
{
private:
    std::string whatString;
public:
    SamePointException(int onePoint, int secondPoint);

    const char* what() const noexcept override;
};

#endif // SAMEPOINTEXCEPTION_H
