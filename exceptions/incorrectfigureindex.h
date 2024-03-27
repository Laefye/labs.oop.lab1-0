#ifndef INCORRECTFIGUREINDEX_H
#define INCORRECTFIGUREINDEX_H
#include <exception>


class IncorrectFigureIndex : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // INCORRECTFIGUREINDEX_H
