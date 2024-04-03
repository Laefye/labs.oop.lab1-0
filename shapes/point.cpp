#include "point.h"

std::string Point::toString() {
    return "(" + std::to_string(this->x) + ", "+ std::to_string(this->y)+")";
}
