#ifndef BADPARAMS_H
#define BADPARAMS_H
#include <exception>
#include <string>


class BadParams : public std::exception {
protected:
    std::string reason;
public:
    BadParams() = default;
    BadParams(const std::string& key);
    const char* what() const noexcept override;
};

#endif // BADPARAMS_H
