#ifndef PARAMS_H
#define PARAMS_H
#include <string>
#include <exception>
#include "point.h"

class BadParams : public std::exception {
protected:
    std::string reason;
public:
    BadParams() = default;
    BadParams(const std::string& key);
    const char* what() const noexcept override;
};

class Params
{
public:
    virtual void get(const std::string& key, std::string& output) const = 0;
    virtual void get(const std::string& key, double& output) const = 0;
    virtual void get(const std::string& key, Point& output) const = 0;

    virtual ~Params() = default;
};

#endif // PARAMS_H
