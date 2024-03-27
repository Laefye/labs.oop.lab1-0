#include "point.h"

std::string Point::toString() const {
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}
