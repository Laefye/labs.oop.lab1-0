#include "incorrectrectanglepoint.h"

IncorrectRectanglePoint::IncorrectRectanglePoint(const std::string& point) {
    reason = "\""+ point + "\" has a incorrect position";
}
