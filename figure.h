#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <exception>

struct Point {
    float x;
    float y;

    std::string toString();
};

class InputException : public std::exception {
private:
    const char* reason;
public:
    InputException(const char* reason);

    const char* what() const noexcept override;
};

class Figure {
private:
    std::string name;
public:
    Figure();
    virtual ~Figure();

    virtual float getArea();
    virtual std::string getParameters();

    std::string getFigureName();
};

#endif // FIGURE_H
